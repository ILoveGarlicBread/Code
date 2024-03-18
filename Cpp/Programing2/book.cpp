#include <iostream>
#include <string>
using namespace std;

class Book {
public:
  string author;
  string title;
  string genre;
  double price;
  string date;
  string publisher;
  string description;
};
int main() {
  Book mybook;
  mybook.author = "somedude";
  mybook.title = "Title of Book";
  mybook.genre = "fiction";
  mybook.price = 1234;
  mybook.date = "12/12/2000";
  mybook.publisher = "Some publisher";
  mybook.description = "This is a book";
  cout << "Author of book: " << mybook.author << endl;

  return 0;
}
