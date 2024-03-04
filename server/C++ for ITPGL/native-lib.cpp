#include <jni.h>
#include <iostream>
#include <string>

// Assuming 'functions.h' declares 'Connect_to_bluetooth_device' correctly.
#include "functions.h"

// Correct JNI method signature, assuming no package name.
extern "C" JNIEXPORT void JNICALL
Java_Main_Connect_to_bluetooth_device(JNIEnv* env, jobject /* this */) {
    try {
        // Call the function from 'functions.h'.
        Connect_to_bluetooth_device();
    } catch (const std::exception& e) {
        // Convert the C++ exception into a Java exception.
        jclass exceptionClass = env->FindClass("java/lang/Exception");
        if (exceptionClass != nullptr) {
            env->ThrowNew(exceptionClass, e.what());
        }
        // If the exception class was not found, you might want to handle it differently.
    }
}
