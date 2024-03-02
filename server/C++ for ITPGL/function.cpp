#include <winsock2.h>
#include <ws2bth.h>
#include <BluetoothAPIs.h>
#include <iostream>
#include <string>

#include "../C++ for ITPGL/functions.h"

#pragma comment(lib, "Bthprops.lib")

void Connect_to_bluetooth_device() {
    WSADATA wsaData;
    HANDLE hRadio, hFind;
    BLUETOOTH_FIND_RADIO_PARAMS btfrp = { sizeof(btfrp) };
    BLUETOOTH_DEVICE_SEARCH_PARAMS btsp = { sizeof(BLUETOOTH_DEVICE_SEARCH_PARAMS) };
    BLUETOOTH_DEVICE_INFO btdi = { sizeof(BLUETOOTH_DEVICE_INFO), 0, };

    // Initialize Winsock
    WSAStartup(MAKEWORD(2,2), &wsaData);

    // Find the first Bluetooth radio
    if (BluetoothFindFirstRadio(&btfrp, &hRadio) != ERROR_SUCCESS) {
        std::cout << "No Bluetooth radios found\n";
        return;
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
        std::cout << "No Bluetooth devices found\n";
        return;
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

    // TODO: Pair with the selected device
    // TODO: Connect to the device
    // TODO: Send data to the device

    // Clean up
    BluetoothFindDeviceClose(hFind);
    BluetoothFindRadioClose(hRadio);
    WSACleanup();
}