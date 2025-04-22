public class Main{
  public static void main(String[] args){
    Machine machine = new Machine("Car1");
    machine.addPart("Engine", 0, 1000);
    machine.addPart("Front Left Wheel", 1, 50);
    machine.addPart("Front Right Wheel", 2, 50);
    machine.addPart("Back Right Wheel", 3, 50);
    machine.addPart("Back Left Wheel", 4, 50);
    machine.addPart("Gas Tank", 5, 100);
    int totalPrice = 0;
    for(Part part : machine.returnAllParts()){
      totalPrice += part.getPrice();
    }
    System.out.println("The total price of all parts is " + totalPrice);

    Machine machine1 = new Machine("Car2");
    int totalPrice1 = 0;
    System.out.println("Add machine 1's engine model to machine 2");
    machine1.addPart(machine.searchPart("Engine"));
    for(Part part : machine1.returnAllParts()){
      totalPrice1 += part.getPrice();
    }
    System.out.println("The total price of all parts for second machine is " + totalPrice1);
  }
}
