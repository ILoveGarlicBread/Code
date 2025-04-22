
public class Publication implements Display {

  private String title;
  private String language;
  private double price;

  public Publication(String inputTitle, String inputLanguage, double inputPrice) {
    title = inputTitle;
    language = inputLanguage;
    price = inputPrice;
  }

  @Override
  public void print() {
    System.out.println(title);
    System.out.println(language);
    System.out.println(price);
    System.out.println();

  }
}
