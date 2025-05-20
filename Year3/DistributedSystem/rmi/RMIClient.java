
import java.rmi.Naming;

public class RMIClient {

  public static void main(String[] args) throws Exception {
    String address = "localhost";
    try {
      Machine machine0 = (Machine) Naming.lookup("rmi://" + address + "machine0");
      Machine machine1 = (Machine) Naming.lookup("rmi://" + address + "machine1");
      Machine machine2 = (Machine) Naming.lookup("rmi://" + address + "machine2");
      System.out.println("Machines' names: ");
      String name0 = machine0.getName();
      String name1 = machine1.getName();
      String name2 = machine2.getName();

      System.out.println("Adding parts: ");
      machine0.addPart("part1", 1, 234);
      machine0.addPart("part2", 2, 345);
      machine1.addPart("part3", 3, 456);
      machine1.addPart("part4", 4, 567);
      machine2.addPart("part5", 5, 345);
      machine2.addPart("part6", 6, 456);
      System.out.println("Searching parts: ");
      // machine0.searchPart(2);
      // machine1.searchPart(3);
      // machine2.searchPart(1);
      // System.out.println("Listing parts: ");
      // machine0.returnAllParts();
      // machine1.returnAllParts();
      // machine2.returnAllParts();

    } catch (Exception e) {
      System.out.println("Client: " + e.getMessage());
      e.printStackTrace();
    }
  }
}
