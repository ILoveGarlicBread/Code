
import java.util.Set;
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Machine extends Remote {
  public Part searchPart(int partNumber) throws RemoteException;

  public void addPart(String partName, int partNumber, int partPrice) throws RemoteException;

  public String getName() throws RemoteException;

  public Set<Part> returnAllParts() throws RemoteException;

}
