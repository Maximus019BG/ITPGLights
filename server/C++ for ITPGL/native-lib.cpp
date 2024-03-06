#include <jni.h>
#include <iostream>
#include <string>

// Include the function from 'functions.h'.
#include "functions.h"

// Correct JNI method signature, assuming no package name.
extern "C" JNIEXPORT void JNICALL
Java_com_example_itpglb_Main_Connect_to_bluetooth_device(JNIEnv* env, jclass /* this */) {
    // Call the function from 'functions.h'.
    Connect_to_bluetooth_device();
}