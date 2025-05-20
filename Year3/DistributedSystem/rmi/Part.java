
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Part extends Remote {
  String getName() throws RemoteException;
  int getNumber() throws RemoteException;
  int getPrice() throws RemoteException;
  void setPrice(int price) throws RemoteException;
}
