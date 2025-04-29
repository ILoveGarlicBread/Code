package exercise3;

public class Part {
  private String name;
  private int number;
  private int price;

  public Part(String inputName, int inputNumber, int inputPrice) {
    this.name = inputName;
    this.number = inputNumber;
    this.price = inputPrice;
  }

  public String getName() {
    return this.name;
  }

  public int getNumber() {
    return this.number;
  }

  public int getPrice() {
    return this.price;
  }

  public void setPrice(int inputPrice) {
    this.price = inputPrice;
  }
}
