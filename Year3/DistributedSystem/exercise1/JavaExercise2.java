
public class JavaExercise2 {
  public static class Puplication {
    private String title;
    private String language;
    private double price;

    public Puplication(String inputTitle, String inputLanguage, double inputPrice) {
      title = inputTitle;
      language = inputLanguage;
      price = inputPrice;
    }

    public void print() {
      System.out.println(title);
      System.out.println(language);
      System.out.println(price);

    }
  }

  public static class Book extends Puplication {
    String Author;
    int ISBN;

    public Book(String inputTitle, String inputLanguage, double inputPrice, String inputAuthor, int inputISBN) {
      super(inputTitle, inputLanguage, inputPrice);
      Author = inputAuthor;
      ISBN = inputISBN;
    }

    public void print() {
      super.print();
      System.out.println(Author);
      System.out.println(ISBN);
    }

  }

  public static void main(String[] args) {
    Puplication newBook = new Puplication("Newtitle", "English", 25);
    Book newBook2 = new Book("Awesome title", "German", 30, "Authorname", 2357);

    Puplication[] array = { newBook, newBook2 };
    for (int i = 0; i < array.length; i++) {
      array[i].print();
      System.out.println();
    }
  }
}
