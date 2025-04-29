import java.io.Serializable;

public class Dish implements Serializable {
    private static final long serialVersionUID = 1L;

    private String name;
    private String nutritionalValue;
    private double price;

    public Dish(String name, String nutritionalValue, double price) {
        this.name = name;
        this.nutritionalValue = nutritionalValue;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public String getNutritionalValue() {
        return nutritionalValue;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }
}

