import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;



@SpringBootApplication
public class BluetoothApplication {

    public static void main(String[] args) {
        SpringApplication.run(BluetoothApplication.class, args);

        try {
            LocalDevice localDevice = LocalDevice.getLocalDevice();
            DiscoveryAgent agent = localDevice.getDiscoveryAgent();

            agent.startInquiry(DiscoveryAgent.GIAC, new DiscoveryListener() {
                public void deviceDiscovered(RemoteDevice btDevice, DeviceClass cod) {
                    try {
                        System.out.println("Device " + btDevice.getBluetoothAddress() + " found, name: " + btDevice.getFriendlyName(false));
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }

                public void inquiryCompleted(int discType) {
                    System.out.println("Device Inquiry completed!");
                    synchronized(BluetoothApplication.class){
                        BluetoothApplication.class.notify();
                    }
                }

                public void serviceSearchCompleted(int transID, int respCode) {}
                public void servicesDiscovered(int transID, ServiceRecord[] servRecord) {}
            });

            try {
                synchronized(BluetoothApplication.class){
                    BluetoothApplication.class.wait();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Finished");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}