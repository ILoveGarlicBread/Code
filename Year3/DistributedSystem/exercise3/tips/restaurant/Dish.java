public class Dish {
  private String name;
  private int nutritionalValue;
  private double price;

  public Dish(String name, int nutritionalValue, double price) {
    this.name = name;
    this.nutritionalValue = nutritionalValue;
    this.price = price;
  }

  public String getName() {
    return name;
  }

  public int getNutritionalValue() {
    return nutritionalValue;
  }

  public double getPrice() {
    return price;
  }

  public void setPrice(double price) {
    this.price = price;
  }

  @Override
  public String toString() {
    return "Dish{name='" + name + "', nutritionalValue=" + nutritionalValue + ", price=" + price + "}";
  }

  // Override equals and hashCode so Dish can be stored in a Set with unique name
  @Override
  public boolean equals(Object obj) {
    if (this == obj)
      return true;
    if (!(obj instanceof Dish))
      return false;
    Dish other = (Dish) obj;
    return this.name.equals(other.name);
  }

  @Override
  public int hashCode() {
    return name.hashCode();
  }
}
