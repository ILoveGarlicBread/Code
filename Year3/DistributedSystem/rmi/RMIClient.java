
import java.rmi.Naming;

import java.util.Set;

public class RMIClient {

  public static void main(String[] args) throws Exception {
    String address = "localhost";
    try {
      Machine machine0 = (Machine) Naming.lookup("rmi://" + address + "/machine0");
      Machine machine1 = (Machine) Naming.lookup("rmi://" + address + "/machine1");
      System.out.println("Machines' names: ");
      System.out.println(machine0.getName());
      System.out.println(machine1.getName() + "\n");

      System.out.println("Adding 2 parts to each machine: ");
      machine0.addPart("part1", 1, 100);
      machine0.addPart("part2", 2, 200);
      machine1.addPart("part3", 3, 300);
      machine1.addPart("part4", 4, 400);
      System.out.println();

      System.out.println("Listing parts and their infos: ");
      System.out.println("Parts of machine0");
      Set<Part> machine0Parts = machine0.returnAllParts();
      int sumPriceOfMachine0 = 0;
      int sumPriceOfMachine1 = 0;
      for (Part part0 : machine0Parts) {
        sumPriceOfMachine0 += part0.getPrice();
        System.out
            .println(
                "Name: " + part0.getName() + ", Num: " + part0.getNumber() + ", Price: " + part0.getPrice());
      }
      System.out.println();
      System.out.println("Total price of parts in machine0: " + sumPriceOfMachine0);

      System.out.println("Parts of machine1");
      Set<Part> machine1Parts = machine1.returnAllParts();
      for (Part part1 : machine1Parts) {
        sumPriceOfMachine1 += part1.getPrice();
        System.out
            .println(
                "Name: " + part1.getName() + ", Num: " + part1.getNumber() + ", Price: " + part1.getPrice());
      }
      System.out.println();
      System.out.println("Total price of parts in machine1: " + sumPriceOfMachine1);
      System.out.println();

      System.out.println("Searching parts: ");
      Part machine0FoundPart = machine0.searchPart(2);
      System.out
          .println("Name: " + machine0FoundPart.getName() + ", Num: " + machine0FoundPart.getNumber() + ", Price: "
              + machine0FoundPart.getPrice());
      Part machine1FoundPart = machine1.searchPart(3);
      System.out.println();
      System.out
          .println("Name: " + machine1FoundPart.getName() + ", Num: " + machine1FoundPart.getNumber() + ", Price: "
              + machine0FoundPart.getPrice());
      System.out.println();

      System.out.println("Changing the price of the found parts: ");
      machine0FoundPart.setPrice(999);
      machine1FoundPart.setPrice(888);
      System.out.println();
      System.out.println("Display new price: ");
      System.out.println("New price of part number 2 in Machine0: " + machine0FoundPart.getPrice());
      System.out.println("New price of part number 3 in Machine1: " + machine1FoundPart.getPrice());

    } catch (Exception e) {
      System.out.println("Client: " + e.getMessage());
      e.printStackTrace();
    }
  }
}
