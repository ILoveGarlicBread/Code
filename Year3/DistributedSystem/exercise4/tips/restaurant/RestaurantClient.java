import java.io.*;
import java.net.*;
import java.util.Scanner;

public class RestaurantClient {

    public static void main(String[] args) {
        try {
            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.println("\n--- Restaurant Client ---");
                System.out.println("Available restaurants: Restaurant1, Restaurant2, Restaurant3");
                System.out.print("Choose restaurant (or 'exit' to quit): ");
                String restaurant = scanner.nextLine();
                if (restaurant.equalsIgnoreCase("exit")) {
                    break;
                }

                System.out.println("Choose operation:");
                System.out.println("1: Add Dish");
                System.out.println("2: Get Dish Names");
                System.out.print("Your choice: ");
                String choice = scanner.nextLine();

                Message message = new Message(restaurant, choice.equals("1") ? "ADD_DISH" : "GET_DISHES");

                if (choice.equals("1")) {
                    System.out.print("Dish name: ");
                    message.setDishName(scanner.nextLine());
                    System.out.print("Nutritional value: ");
                    message.setNutritionalValue(scanner.nextLine());
                    System.out.print("Price: ");
                    message.setPrice(Double.parseDouble(scanner.nextLine()));
                }

                // Connect to server
                Socket socket = new Socket("localhost", 9876);

                ObjectOutputStream out = new ObjectOutputStream(socket.getOutputStream());
                ObjectInputStream in = new ObjectInputStream(socket.getInputStream());

                out.writeObject(message);

                Message response = (Message) in.readObject();
                System.out.println("\nServer response: " + response.getResponse());

                in.close();
                out.close();
                socket.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

