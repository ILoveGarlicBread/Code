// SparePart.java
package model;

public class SparePart {
  private String name;
  private int number;
  private double price;

  public SparePart(String name, int number, double price) {
    this.name = name;
    this.number = number;
    this.price = price;
  }

  public String getName() {
    return name;
  }

  public int getNumber() {
    return number;
  }

  public double getPrice() {
    return price;
  }

  public void setPrice(double price) {
    this.price = price;
  }
}
