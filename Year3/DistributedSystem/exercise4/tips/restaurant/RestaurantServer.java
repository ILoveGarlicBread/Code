import java.io.*;
import java.net.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class RestaurantServer {

    private static Map<String, Restaurant> restaurants = new HashMap<>();

    public static void main(String[] args) {
        try {
            // Create 3 restaurants
            restaurants.put("Restaurant1", new Restaurant("Restaurant1"));
            restaurants.put("Restaurant2", new Restaurant("Restaurant2"));
            restaurants.put("Restaurant3", new Restaurant("Restaurant3"));

            ServerSocket serverSocket = new ServerSocket(9876);
            System.out.println("Server started on port 9876...");

            while (true) {
                Socket connectionSocket = serverSocket.accept();
                System.out.println("Client connected!");

                ObjectInputStream in = new ObjectInputStream(connectionSocket.getInputStream());
                ObjectOutputStream out = new ObjectOutputStream(connectionSocket.getOutputStream());

                Message request = (Message) in.readObject();
                Message response = handleRequest(request);

                out.writeObject(response);

                in.close();
                out.close();
                connectionSocket.close();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static Message handleRequest(Message request) {
        String restaurantName = request.getRestaurantName();
        String operation = request.getOperation();

        Message response = new Message(restaurantName, operation);

        Restaurant restaurant = restaurants.get(restaurantName);
        if (restaurant == null) {
            response.setResponse("ERROR: Restaurant not found.");
            return response;
        }

        switch (operation) {
            case "ADD_DISH":
                restaurant.addDish(request.getDishName(), request.getNutritionalValue(), request.getPrice());
                response.setResponse("Dish added successfully.");
                break;
            case "GET_DISHES":
                Set<Dish> dishes = restaurant.getDishes();
                if (dishes.isEmpty()) {
                    response.setResponse("No dishes found.");
                } else {
                    StringBuilder sb = new StringBuilder();
                    for (Dish d : dishes) {
                        sb.append(d.getName()).append(",");
                    }
                    response.setResponse(sb.substring(0, sb.length() - 1)); // Remove trailing comma
                }
                break;
            default:
                response.setResponse("ERROR: Unknown operation.");
        }
        return response;
    }
}

