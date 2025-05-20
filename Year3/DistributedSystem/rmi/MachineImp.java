
import java.rmi.*;
import java.rmi.server.*;
import java.util.HashSet;
import java.util.Set;

public class MachineImp extends UnicastRemoteObject implements Machine {
  private final String name;
  private final Set<Part> parts;

  public MachineImp(String name) throws RemoteException {
    this.name = name;
    this.parts = new HashSet<>();
  }

  public String getName() throws RemoteException {
    return name;
  }

  public Part searchPart(int number) throws RemoteException {
    System.out.println("Invocation of searchPart().");
    for (Part part : parts) {
      if (part.getNumber() == number) {
        return part;
      }
    }
    System.out.println("There is no part with number " + number);
    return null;
  }

  public void addPart(String name, int number, int price) throws RemoteException {
    System.out.println("Invocation of addPart().");
    Part part = new PartImp(name, number, price);
    parts.add(part);

  }

  public void addPart(Part part) {
    parts.add(part);
  }

  public Set<Part> returnAllParts() throws RemoteException {
    return parts;
  }

}
