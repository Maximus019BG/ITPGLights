package com.example.itpglb;

public class Main {

    static {
        try {
            
            System.loadLibrary("native-lib");
            System.out.println("Successfully loaded native library");
           
          
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Could not load native library: " + e.getMessage());
        }
    }
   
    static{
        System.loadLibrary("native-lib");
    }
    
    public static native void Connect_to_bluetooth_device();

    
    public static void ConnectDevice() {
        Connect_to_bluetooth_device();
    }
    public static void main(String[] args) {
        ConnectDevice();
    }
}