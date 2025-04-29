import java.io.Serializable;
import java.util.HashSet;
import java.util.Set;

public class Restaurant implements Serializable {
    private static final long serialVersionUID = 1L;

    private String name;
    private Set<Dish> dishes;

    public Restaurant(String name) {
        this.name = name;
        this.dishes = new HashSet<>();
    }

    public void addDish(String name, String nutritionalValue, double price) {
        dishes.add(new Dish(name, nutritionalValue, price));
    }

    public Set<Dish> getDishes() {
        return dishes;
    }

    public String getName() {
        return name;
    }
}

