import java.util.HashSet;
import java.util.Set;

public class Restaurant {
  private String name;
  private Set<Dish> dishes;

  public Restaurant(String name) {
    this.name = name;
    this.dishes = new HashSet<>();
  }

  public Dish searchDishByName(String dishName) {
    for (Dish dish : dishes) {
      if (dish.getName().equals(dishName)) {
        return dish;
      }
    }
    return null;
  }

  public void addDish(String name, int nutritionalValue, double price) {
    Dish dish = new Dish(name, nutritionalValue, price);
    dishes.add(dish);
  }

  public Set<Dish> getDishes() {
    return dishes;
  }

  public String getName() {
    return name;
  }
}
