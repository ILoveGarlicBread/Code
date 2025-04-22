public class Plane {
  private String name;
  private String type;
  private int numberOfSeats;

  public Plane(String name, String type, int numberOfSeats) {
    this.name = name;
    this.type = type;
    this.numberOfSeats = numberOfSeats;
  }

  public String getName() {
    return name;
  }

  public String getType() {
    return type;
  }

  public int getNumberOfSeats() {
    return numberOfSeats;
  }

  public void setNumberOfSeats(int numberOfSeats) {
    this.numberOfSeats = numberOfSeats;
  }

  @Override
  public String toString() {
    return "Plane{name='" + name + "', type='" + type + "', seats=" + numberOfSeats + "}";
  }
}
