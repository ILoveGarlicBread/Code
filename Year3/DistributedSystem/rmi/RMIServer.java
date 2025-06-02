
import java.rmi.*;

public class RMIServer {
  public static void main(String[] args) {
    try {
      MachineImp machine0 = new MachineImp("machine0");
      MachineImp machine1 = new MachineImp("machine1");
      Naming.rebind("machine0", machine0);
      Naming.rebind("machine1", machine1);
      System.out.println("Server running...");
    } catch (Exception e) {
      System.out.println("Server: " + e.getMessage());
      e.printStackTrace();
    }
  }
}
