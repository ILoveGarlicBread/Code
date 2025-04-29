import exercise3.*;
import java.net.*;
import java.io.*;
import java.util.*;

public class UDPServer {
  private static Map<String, Machine> machines = new HashMap<>();

  public static void main(String[] args) {
    Machine car = new Machine("Car");
    Machine plane = new Machine("Plane");
    Machine boat = new Machine("Boat");
    machines.put("Car", car);
    machines.put("Plane", plane);
    machines.put("Boat", boat);

    System.out.println("The Server is running");
    try {
      DatagramSocket aSocket = new DatagramSocket(9999);
      byte[] buffer = new byte[1000];
      while (true) {
        DatagramPacket request = new DatagramPacket(buffer, buffer.length);
        aSocket.receive(request);
        String stringRequest = new String(request.getData(), 0, request.getLength());
        System.out.println(" Request: " + stringRequest);
        String[] arguments = stringRequest.split(",");
        if (arguments.length < 2) {
          System.out.println("Incomplete or short request.");
        }
        String machineName = arguments[0];
        String operation = arguments[1];
        Machine machine = machines.get(machineName);
        if (machine == null) {
          System.out.println(machineName + "do not exist.");
        }
        switch (operation) {
          case "addPart":
            if (arguments.length != 5) {
              System.out.println("Invalid format for addPart");
            }
          case "listPart":
            String partName = arguments[2];
            int partNumber = arguments[3];
        }
        DatagramPacket reply = new DatagramPacket(request.getData(),
            request.getLength(), request.getAddress(), request.getPort());
        aSocket.send(reply);
        aSocket.close();
      }
    } catch (SocketException e) {
      System.out.println(" Socket: " + e.getMessage());
    } catch (IOException e) {
      System.out.println(" IO: " + e.getMessage());
    }
  }

}
