import exercise3.*;
import java.net.*;
import java.io.*;
import java.util.*;

public class UDPServer {
  private static final Map<Integer, Machine> machines = new HashMap<>();

  public static void main(String[] args) {
    machines.put(0, new Machine("Car"));
    machines.put(1, new Machine("Plane"));
    machines.put(2, new Machine("Boat"));

    System.out.print("\033[H\033[2J");
    System.out.println("The Server is running");

    try (DatagramSocket aSocket = new DatagramSocket(9999)) {
      byte[] buffer = new byte[1024];

      while (true) {
        DatagramPacket request = new DatagramPacket(buffer, buffer.length);
        aSocket.receive(request);

        ByteArrayInputStream inputByte = new ByteArrayInputStream(request.getData(), 0, request.getLength());
        DataInputStream inputData = new DataInputStream(inputByte);

        String response = "";
        int requestCode = inputData.readInt();

        try {

          int machineId = (requestCode / 1000000) % 10;
          int operationId = (requestCode / 100000) % 10;
          Machine machine = machines.get(machineId);

          if (machine == null) {
            response = "Machine with ID " + machineId + " dont exist";
          } else {
            switch (operationId) {
              case 0: {
                // System.out.println("Part list:\n0 = screw\n1 = piston\n2 = gear\n3 =
                // battery\n4 = engine");
                int partID = (requestCode / 10000) % 10;
                String partName = "";
                switch (partID) {
                  case 0:
                    partName = "Screw";
                  case 1:
                    partName = "Piston";
                  case 2:
                    partName = "Gear";
                  case 3:
                    partName = "Battery";
                  case 4:
                    partName = "Engine";
                }
                int partNumber = (requestCode / 1000) % 10;
                int partPrice = requestCode % 10;

                machine.addPart(partName, partNumber, partPrice);
                response = "Part added successfully";
                System.out.println("Replying: " + response);
                break;
              }

              case 1: {
                Set<Part> parts = machine.returnAllParts();
                if (parts.isEmpty()) {
                  response = "There is no parts in " + machine.getName();
                } else {
                  StringBuilder sb = new StringBuilder();
                  for (Part part : parts) {
                    sb.append(part.getName()).append(",");
                  }
                  response = sb.substring(0, sb.length() - 1);
                  System.out.println("Replying: " + response);
                }
                break;
              }

              default:
                response = "Unknown operation: " + operationId;
            }
          }
        } catch (Exception e) {
          response = "Error" + e.getMessage();
        }

        byte[] sendData = response.getBytes();
        DatagramPacket reply = new DatagramPacket(sendData, sendData.length, request.getAddress(), request.getPort());
        aSocket.send(reply);
      }

    } catch (IOException e) {
      System.out.println("Server IO error: " + e.getMessage());
    }
  }
}
