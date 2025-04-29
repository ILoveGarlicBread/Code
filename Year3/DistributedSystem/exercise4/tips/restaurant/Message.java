import java.io.Serializable;

public class Message implements Serializable {
    private static final long serialVersionUID = 1L;

    private String restaurantName;
    private String operation;
    private String dishName;
    private String nutritionalValue;
    private double price;
    private String response;

    // Constructors
    public Message(String restaurantName, String operation) {
        this.restaurantName = restaurantName;
        this.operation = operation;
    }

    // Getters and Setters
    public String getRestaurantName() {
        return restaurantName;
    }

    public String getOperation() {
        return operation;
    }

    public String getDishName() {
        return dishName;
    }

    public void setDishName(String dishName) {
        this.dishName = dishName;
    }

    public String getNutritionalValue() {
        return nutritionalValue;
    }

    public void setNutritionalValue(String nutritionalValue) {
        this.nutritionalValue = nutritionalValue;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getResponse() {
        return response;
    }

    public void setResponse(String response) {
        this.response = response;
    }
}

