#include <winsock2.h>
#include <ws2bth.h>
#include <BluetoothAPIs.h>
#include <iostream>
#include <string>
#include <stdexcept>

#include "../C++ for ITPGL/functions.h"


#pragma comment(lib, "Bthprops.lib")
#pragma comment(lib, "Ws2_32.lib") // Add this line

void str2ba(const char* str, BLUETOOTH_ADDRESS* btaddr) {
    unsigned int b[6];

    if (sscanf_s(str, "%02x:%02x:%02x:%02x:%02x:%02x", &b[0], &b[1], &b[2], &b[3], &b[4], &b[5]) != 6) {
        throw std::runtime_error("Invalid MAC address format");
    }

    for (int i = 0; i < 6; ++i) {
        btaddr->rgBytes[i] = static_cast<uint8_t>(b[i]);
    }
}

void Connect_to_bluetooth_device() {
    WSADATA wsaData;
    HANDLE hRadio = NULL, hFind = NULL;
    BLUETOOTH_FIND_RADIO_PARAMS btfrp = { sizeof(btfrp) };
    BLUETOOTH_DEVICE_SEARCH_PARAMS btsp = { sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS) };
    BLUETOOTH_DEVICE_INFO btdi = { sizeof(BLUETOOTH_DEVICE_INFO), 0, };

    try {
        // Initialize Winsock
        if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
            throw std::runtime_error("WSAStartup failed");
        }

        // Find the first Bluetooth radio
        if (BluetoothFindFirstRadio(&btfrp, &hRadio) != ERROR_SUCCESS) {
            throw std::runtime_error("No Bluetooth radios found");
        }

        // Set the search parameters
        btsp.fReturnAuthenticated = TRUE;
        btsp.fReturnRemembered = TRUE;
        btsp.fReturnUnknown = TRUE;
        btsp.fReturnConnected = TRUE;
        btsp.fIssueInquiry = TRUE;
        btsp.cTimeoutMultiplier = 2;
        btsp.hRadio = hRadio;

        // Find the first Bluetooth device
        hFind = BluetoothFindFirstDevice(&btsp, &btdi);
        if (hFind == NULL) {
            throw std::runtime_error("No Bluetooth devices found");
        }

        // Print the name and address of each device
        do {
            std::cout << "Device: " << btdi.szName << ", Address: " <<
                btdi.Address.rgBytes[5] << ":" <<
                btdi.Address.rgBytes[4] << ":" <<
                btdi.Address.rgBytes[3] << ":" <<
                btdi.Address.rgBytes[2] << ":" <<
                btdi.Address.rgBytes[1] << ":" <<
                btdi.Address.rgBytes[0] << "\n";
        } while (BluetoothFindNextDevice(hFind, &btdi));

        // Prompt the user to select a device
        std::cout << "Enter the MAC address of the device you want to connect to: ";
        std::string mac_address;
        std::cin >> mac_address;

        // Pair with the selected device
        BLUETOOTH_DEVICE_INFO_STRUCT deviceInfo = { sizeof(BLUETOOTH_DEVICE_INFO_STRUCT) };
        str2ba(mac_address.c_str(), &deviceInfo.Address);
        DWORD pcServices = 16;
        GUID guids[16];
        DWORD result = BluetoothAuthenticateDeviceEx(NULL, hRadio, &deviceInfo, NULL, MITMProtectionNotRequired);
        if (result != ERROR_SUCCESS) {
            throw std::runtime_error("BluetoothAuthenticateDeviceEx failed");
        }

        // Connect to the device
        SOCKADDR_BTH sa = { 0 };
        sa.addressFamily = AF_BTH;
        sa.btAddr = deviceInfo.Address.ullLong;
        sa.serviceClassId = SerialPortServiceClass_UUID;
        sa.port = BT_PORT_ANY;
        SOCKET s = socket(AF_BTH, SOCK_STREAM, BTHPROTO_RFCOMM);
        if (s == INVALID_SOCKET) {
            throw std::runtime_error("socket failed");
        }
        if (connect(s, (SOCKADDR*)&sa, sizeof(sa)) == SOCKET_ERROR) {
            closesocket(s);
            throw std::runtime_error("connect failed");
        }

        // Send data to the device
        const char* data = "Hello, Bluetooth!";
        int bytes_sent = send(s, data, strlen(data), 0);
        if (bytes_sent == SOCKET_ERROR) {
            closesocket(s);
            throw std::runtime_error("send failed");
        }

        // Close the socket
        closesocket(s);

        // Clean up
        if (hFind && !BluetoothFindDeviceClose(hFind)) {
            throw std::runtime_error("BluetoothFindDeviceClose failed");
        }
        if (hRadio && !BluetoothFindRadioClose(hRadio)) {
            throw std::runtime_error("BluetoothFindRadioClose failed");
        }
        if (WSACleanup() == SOCKET_ERROR) {
            throw std::runtime_error("WSACleanup failed");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        // Clean up in case of error
        if (hFind) BluetoothFindDeviceClose(hFind);
        if (hRadio) BluetoothFindRadioClose(hRadio);
        WSACleanup();
    }
}