import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class AirlineClient {

    public static void main(String[] args) {
        try {
            DatagramSocket clientSocket = new DatagramSocket();
            InetAddress serverIP = InetAddress.getByName("localhost");
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.println("\n--- Airline Client ---");
                System.out.println("Available airlines: Airline1, Airline2, Airline3");
                System.out.print("Choose airline (or 'exit' to quit): ");
                String airline = scanner.nextLine();
                if (airline.equalsIgnoreCase("exit")) {
                    break;
                }

                System.out.println("Choose operation:");
                System.out.println("1: Add Plane");
                System.out.println("2: Get Plane Names");
                System.out.print("Your choice: ");
                String choice = scanner.nextLine();

                String request = "";

                if (choice.equals("1")) {
                    System.out.print("Plane name: ");
                    String planeName = scanner.nextLine();
                    System.out.print("Plane type: ");
                    String planeType = scanner.nextLine();
                    System.out.print("Number of seats: ");
                    String seats = scanner.nextLine();
                    request = airline + ";ADD_PLANE;" + planeName + ";" + planeType + ";" + seats;
                } else if (choice.equals("2")) {
                    request = airline + ";GET_PLANES";
                } else {
                    System.out.println("Invalid choice.");
                    continue;
                }

                // Send request
                byte[] sendData = request.getBytes();
                DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverIP, 9876);
                clientSocket.send(sendPacket);

                // Receive response
                byte[] receiveData = new byte[1024];
                DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                clientSocket.receive(receivePacket);

                String response = new String(receivePacket.getData(), 0, receivePacket.getLength());
                System.out.println("\nServer response: " + response);
            }

            clientSocket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
