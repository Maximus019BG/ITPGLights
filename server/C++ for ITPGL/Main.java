public class Main {
    // Declare the native method
    public native void Func();

    // Load the native library
    static {
        System.loadLibrary("native-lib");
    }

    // Main method
    public static void main(String[] args) {
        Main m = new Main();
        m.Func(); 
    }
}