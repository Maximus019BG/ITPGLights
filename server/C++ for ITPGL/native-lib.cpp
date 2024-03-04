#include <jni.h>
#include <iostream>
#include <string>

// Assuming 'functions.h' declares 'Connect_to_bluetooth_device' correctly.
#include "functions.h"
#include "..\C++ for ITPGL\SpringBoot\itpgl-b\src\main\java\com\example\itpglb\Main.h"

// Correct JNI method signature, assuming no package name.
extern "C" JNIEXPORT void JNICALL
Java_Main_Connect_to_bluetooth_device(JNIEnv* env, jobject /* this */) {
   
        // Call the function from 'functions.h'.
        Connect_to_bluetooth_device();
   
}