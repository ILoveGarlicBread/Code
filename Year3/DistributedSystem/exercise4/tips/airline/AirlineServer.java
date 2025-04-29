import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.*;

public class AirlineServer {

    private static Map<String, Airline> airlines = new HashMap<>();

    public static void main(String[] args) {
        try {
            // Create airlines
            airlines.put("Airline1", new Airline("Airline1"));
            airlines.put("Airline2", new Airline("Airline2"));
            airlines.put("Airline3", new Airline("Airline3"));

            DatagramSocket serverSocket = new DatagramSocket(9876);
            System.out.println("Server started on port 9876...");

            byte[] receiveData = new byte[1024];
            byte[] sendData;

            while (true) {
                // Receive packet
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                serverSocket.receive(receivePacket);
                String clientMessage = new String(receivePacket.getData(), 0, receivePacket.getLength());
                System.out.println("Received: " + clientMessage);

                // Handle request
                String response = handleRequest(clientMessage);

                // Send response
                sendData = response.getBytes();
                InetAddress clientIP = receivePacket.getAddress();
                int clientPort = receivePacket.getPort();
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, clientIP, clientPort);
                serverSocket.send(sendPacket);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static String handleRequest(String request) {
        // request format: airlineName;operation;[params...]
        String[] parts = request.split(";");
        if (parts.length < 2) {
            return "ERROR: Invalid request.";
        }

        String airlineName = parts[0];
        String operation = parts[1];

        Airline airline = airlines.get(airlineName);
        if (airline == null) {
            return "ERROR: Airline not found.";
        }

        switch (operation) {
            case "ADD_PLANE":
                if (parts.length != 5) {
                    return "ERROR: Invalid ADD_PLANE format.";
                }
                String planeName = parts[2];
                String planeType = parts[3];
                int seats;
                try {
                    seats = Integer.parseInt(parts[4]);
                } catch (NumberFormatException e) {
                    return "ERROR: Seats must be a number.";
                }
                airline.addPlane(planeName, planeType, seats);
                return "Plane added successfully.";
            case "GET_PLANES":
                Set<Plane> planes = airline.getPlanes();
                if (planes.isEmpty()) {
                    return "No planes found.";
                }
                StringBuilder sb = new StringBuilder();
                for (Plane p : planes) {
                    sb.append(p.getName()).append(",");
                }
                return sb.substring(0, sb.length() - 1); // Remove trailing comma
            default:
                return "ERROR: Unknown operation.";
        }
    }
}

