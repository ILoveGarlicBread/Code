import java.net.*;
import java.io.*;
import java.util.Scanner;

public class UDPClient {
  public static void main(String[] args) {
    try (DatagramSocket aSocket = new DatagramSocket();
        Scanner scanner = new Scanner(System.in)) {

      InetAddress serverHost = InetAddress.getByName("localhost");
      int serverPort = 9999;
      System.out.print("\033[H\033[2J");
      while (true) {

        System.out.println("Select Machine:");
        System.out.println("0 = Car,\n1 = Plane,\n2 = Boat");
        int machineId = scanner.nextInt();

        System.out.print("\033[H\033[2J");
        System.out.println("Select Operation:");
        System.out.println("0 = addPart, 1 = listPart");
        int operationId = scanner.nextInt();
        int requestCode = machineId * 1000000 + operationId * 100000;
        scanner.nextLine();

        ByteArrayOutputStream outputByte = new ByteArrayOutputStream();
        DataOutputStream outputData = new DataOutputStream(outputByte);

        if (operationId == 0) {
          System.out.println("Part list:\n0 = screw\n1 = piston\n2 = gear\n3 = battery\n4 = engine");
          System.out.print("Enter part name: ");
          int partID = scanner.nextInt();
          System.out.print("Enter part number: ");
          int partNumber = scanner.nextInt();
          System.out.print("Enter part price: ");
          int partPrice = scanner.nextInt();
          requestCode += partID * 10000 + partNumber * 1000 + partPrice;
          outputData.writeInt(requestCode);
        }
        outputData.writeInt(requestCode);

        byte[] sendData = outputByte.toByteArray();
        DatagramPacket request = new DatagramPacket(sendData, sendData.length, serverHost, serverPort);
        aSocket.send(request);

        byte[] buffer = new byte[1024];
        DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
        aSocket.receive(reply);

        String response = new String(reply.getData(), 0, reply.getLength());
        System.out.print("\033[H\033[2J");
        System.out.println("Server Response: " + response);
      }
    } catch (IOException e) {
      System.out.println("Client IO error: " + e.getMessage());
    }
  }
}
