
public class Book extends Publication {
  String Author;
  int ISBN;

  public Book(String inputTitle, String inputLanguage, double inputPrice, String inputAuthor, int inputISBN) {
    super(inputTitle, inputLanguage, inputPrice);
    Author = inputAuthor;
    ISBN = inputISBN;
  }

  @Override
  public void print() {
    super.print();
    System.out.println(Author);
    System.out.println(ISBN);
    System.out.println();
  }

}
