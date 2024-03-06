#include <jni.h>
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2bth.h>
#include <BluetoothAPIs.h>
#include <stdexcept>

// Include the function from 'functions.h'.
#include "functions.h"

// Correct JNI method signature, assuming no package name.
extern "C" JNIEXPORT void JNICALL
Java_com_example_itpglb_Main_ConnectToBluetooth(JNIEnv* env, jclass /* this */) {
        
        Connect_to_bluetooth_device();
}