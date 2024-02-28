@echo off

REM Define the paths to the JDK include directories
set INCLUDE_PATH1=D:/java/JDK/include
set INCLUDE_PATH2=D:/java/JDK/include/win32

REM Define the name of the C++ source file and the output DLL
set SOURCE_FILE=native-lib.cpp
set OUTPUT_DLL=native-lib.dll

REM Compile the C++ code into a DLL
g++ -I%INCLUDE_PATH1% -I%INCLUDE_PATH2% -shared -o %OUTPUT_DLL% %SOURCE_FILE%

echo Compilation finished. Output: %OUTPUT_DLL%

REM Define the name of the Java file to compile and run
set JAVA_FILE="D:/ITPGL/ITPGLights/server/C++ for ITPGL/Main.java"

REM Compile the Java file
javac %JAVA_FILE%

REM If the Java file compiled successfully, run it
if %errorlevel% equ 0 (
    echo Running Java program...
    java Main
) else (
    echo Java compilation failed.
)
