@echo off
REM Define the paths to the JDK include directories
set INCLUDE_PATH1=D:/java/JDK/include
set INCLUDE_PATH2=D:/java/JDK/include/win32

REM Define the name of the C++ source file and the output DLL
set SOURCE_FILE1=native-lib.cpp
set SOURCE_FILE2=function.cpp
set OUTPUT_DLL=native-lib.dll

REM Compile the C++ code into a DLL
cd "D:\ITPGL\ITPGLights\server\C++ for ITPGL"
g++ -I%INCLUDE_PATH1% -I%INCLUDE_PATH2% -shared -o %OUTPUT_DLL% %SOURCE_FILE1% %SOURCE_FILE2% -lws2_32 -lbthprops
echo Compilation finished. Output: %OUTPUT_DLL%

REM Define the name of the Java file to compile and run
set JAVA_FILE="D:\ITPGL\ITPGLights\server\C++ for ITPGL\SpringBoot\itpgl-b\src\main\java\com\example\itpglb\Main.java"

REM Compile the Java file
javac %JAVA_FILE%
cd "D:\ITPGL\ITPGLights\server\C++ for ITPGL\SpringBoot\itpgl-b"
./mvnw spring-boot:run

set JAVA_OPTS="-Djava.library.path=D:\ITPGL\ITPGLights\server\C++ for ITPGL"

REM If the Java file compiled successfully, run it
if %errorlevel% equ 0 (
    echo Running Java program... 
    REM Run the Java program with the JAVA_OPTS
    java %JAVA_OPTS% Main
) else (
    echo Java compilation failed.
)