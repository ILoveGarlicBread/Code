
import java.rmi.*;
import java.rmi.registry.LocateRegistry;

public class RMIServer {
  public static void main(String[] args) {
    try {
      // LocateRegistry.createRegistry(9999);
      MachineImp machine0 = new MachineImp("Machine0");
      MachineImp machine1 = new MachineImp("Machine1");
      MachineImp machine2 = new MachineImp("Machine2");
      Naming.rebind("Machine0", machine0);
      Naming.rebind("Machine1", machine1);
      Naming.rebind("Machine2", machine2);
      System.out.println("Server running...");
    } catch (Exception e) {
      System.out.println("Server: " + e.getMessage());
      e.printStackTrace();
    }
  }
}
