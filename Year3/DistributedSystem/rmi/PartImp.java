
import java.rmi.*;
import java.rmi.server.*;

public class PartImp extends UnicastRemoteObject implements Part {
  private final String name;
  private final int number;
  private int price;

  public PartImp(String name, int number, int price) throws RemoteException {
    this.name = name;
    this.number = number;
    this.price = price;
  }

  public String getName() throws RemoteException {
    return name;
  }

  public int getNumber() throws RemoteException {
    return number;
  }

  public int getPrice() throws RemoteException {
    return price;
  }

  public void setPrice(int price) throws RemoteException {
    this.price = price;
  }

}
