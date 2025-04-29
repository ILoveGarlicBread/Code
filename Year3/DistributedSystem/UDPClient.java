
import java.net.*;
import java.io.*;
import java.util.Scanner;

public class UDPClient {
  public static void main(String args[]) {
    try {

      Scanner scanner = new Scanner(System.in);
      DatagramSocket aSocket = new DatagramSocket();
      InetAddress aHost = InetAddress.getByName("localhost");
      int serverPort = 9999;
      while (true) {
        System.out.println("Client for Machines");
        System.out.println("There are 3 Machines");
        System.out.println("Car \nPlane \nBoat");
        System.out.print("Choose one: ");
        String machineName = scanner.nextLine();
        if (machineName.equalsIgnoreCase(":q")) {
          break;
        }
        System.out.println("Choose options: ");
        System.out.println("Add a new part: [1]");
        System.out.println("List all parts: [2]");
        System.out.println("Choice: ");
        String message = "";
        String choice = scanner.nextLine();
        if (choice.equals("1")) {
          System.out.print("Part name: ");
          String partName = scanner.nextLine();
          System.out.print("Part number: ");
          String partNumber = scanner.nextLine();
          System.out.print("Part price: ");
          String partPrice = scanner.nextLine();
          message = machineName + ",addPart," + partName + "," + partNumber + "," + partPrice;
        } else if (choice.equals("2")) {
          message = machineName + ",listPart";
        } else {
          System.out.println("Invalid choice.");
          continue;
        }

        byte[] m = message.getBytes();
        DatagramPacket request = new DatagramPacket(m, m.length,
            aHost, serverPort);
        aSocket.send(request);

        byte[] buffer = new byte[1000];
        DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
        aSocket.receive(reply);
        System.out.println(" Reply: " + new String(reply.getData()));
      }
    } catch (SocketException e) {
      System.out.println(" Socket: " + e.getMessage());
    } catch (IOException e) {
      System.out.println(" IO: " + e.getMessage());
    }
  }

}
