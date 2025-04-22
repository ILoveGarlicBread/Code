public class Car implements Display {
  private String colour;
  private int horsepower;
  private int weight;

  public Car(String inputColour, int inputHorsepower, int inputWeight) {
    this.colour = inputColour;
    this.horsepower = inputHorsepower;
    this.weight = inputWeight;
  }

  @Override
  public void print() {
    System.out.println("Colours: " + colour);
    System.out.println("Horsepower: " + horsepower);
    System.out.println("Weight " + weight);
    System.out.println();

  }
}
