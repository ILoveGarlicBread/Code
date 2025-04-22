import java.sql.Array;

public class Main {
  public static void main(String[] args) {
    Display[] displayArray = new Display[3];

    Car car1 = new Car("Red", 300, 20);
    Publication book1 = new Publication("book1", "English", 30);
    Book book2 = new Book("book2", "German", 25, "authorname2", 2345);
    displayArray[0] = car1;
    displayArray[1] = book1;
    displayArray[2] = book2;
    for (int i = 0; i < displayArray.length; i++) {
      displayArray[i].print();
    }
  }
}
