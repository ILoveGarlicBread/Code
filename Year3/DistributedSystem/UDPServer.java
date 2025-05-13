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
      boolean status = true;
      while (status) {
        DatagramPacket request = new DatagramPacket(buffer, buffer.length);
        aSocket.receive(request);

        String stringRequest = new String(request.getData(), 0, request.getLength());
        System.out.println("Request: " + stringRequest);

        String[] arguments = stringRequest.split(",");
        String response = "";

        if (arguments.length < 2) {
          response = "Incomplete or short request.";
        } else {
          String machineName = arguments[0];
          String operation = arguments[1];
          Machine machine = machines.get(machineName);

          if (machine == null) {
            response = machineName + " does not exist.";
          } else {
            switch (operation) {
              case "addPart":
                if (arguments.length != 5) {
                  response = "Invalid format for addPart.";
                } else {
                  try {
                    String partName = arguments[2];
                    int partNumber = Integer.parseInt(arguments[3]);
                    int partPrice = Integer.parseInt(arguments[4]);
                    machine.addPart(partName, partNumber, partPrice);
                    response = "Part added successfully.";
                  } catch (NumberFormatException e) {
                    response = "Invalid number format.";
                  }
                }
                break;

              case "listPart":
                Set<Part> parts = machine.returnAllParts();
                if (parts.isEmpty()) {
                  response = "There is no part currently in " + machineName;
                } else {
                  StringBuilder sb = new StringBuilder();
                  for (Part part : parts) {
                    sb.append(part.getName()).append(",");
                  }
                  response = sb.substring(0, sb.length() - 1);
                }
                break;

              default:
                response = "Invalid operation.";
            }
          }
        }

        byte[] sendData = response.getBytes();
        DatagramPacket reply = new DatagramPacket(sendData, sendData.length, request.getAddress(), request.getPort());
        aSocket.send(reply);
      }
    } catch (SocketException e) {
      System.out.println("Socket error: " + e.getMessage());
    } catch (IOException e) {
      System.out.println("IO error: " + e.getMessage());
    }
  }
}
