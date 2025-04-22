public class Main {
  public static void main(String[] args) {
    Restaurant restaurant = new Restaurant("Tasty Bites");

    restaurant.addDish("Spaghetti", 450, 8.99);
    restaurant.addDish("Salad", 150, 5.49);
    restaurant.addDish("Burger", 700, 9.49);

    System.out.println("Dishes served at " + restaurant.getName() + ":");
    for (Dish d : restaurant.getDishes()) {
      System.out.println(d);
    }

    System.out.println("\nSearching for dish 'Burger':");
    Dish found = restaurant.searchDishByName("Burger");
    if (found != null) {
      System.out.println("Found: " + found);
    } else {
      System.out.println("Dish not found.");
    }

    double totalPrice = 0;
    int count = 0;
    for (Dish d : restaurant.getDishes()) {
      totalPrice += d.getPrice();
      count++;
    }

    double averagePrice = (count > 0) ? totalPrice / count : 0;
    System.out.printf("\nAverage price of all dishes: $%.2f\n", averagePrice);
  }
}
