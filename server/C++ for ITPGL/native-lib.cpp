#include <jni.h>
#include <iostream>
#include <string>


#include "Main.h"
#include "functions.h" 
#include "function.cpp"


extern "C" JNIEXPORT void JNICALL
Java_Main_Func(JNIEnv* env, jobject /* this */) {
    Func();
}