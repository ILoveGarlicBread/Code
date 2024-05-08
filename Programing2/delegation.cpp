#include <iostream>
using namespace std;
class Date {
  int day, month, year;

public:
  Date(int d, int m, int y) {
    this->day = d;
    this->month = m;
    this->year = y;
  }
  int getday() { return day; }
  int getmonth() { return month; }
  void describe() { cout << day << "/" << month << "/" << year << endl; }
};

class Person {
private:
  string name;
  Date *birth;

public:
  Person(string name, Date *birth) : name(name), birth(birth) {}
  void describe() {
    cout << "Name: " << name << endl;
    cout << "Birth: ";
    birth->describe();
  }
  bool checkSameName(Person other) {
    if (this->name == other.name) {
      return 1;
    }
    return 0;
  }
  bool checkSameBirthday(Person other) {
    if (other.birth->getday() == this->birth->getday() &&
        other.birth->getmonth() == this->birth->getmonth()) {
      return 1;
    }
    return 0;
  }
  bool operator==(Person &other) {
    return checkSameName(other) && checkSameBirthday(other);
  }
};
int main() {
  Date date(1, 1, 2000);
  Person John("John", &date);
  John.describe();
  Date date2(1, 1, 1999);
  Person Sam("Sam", &date2);
  Sam.describe();
  Person John1("John", &date);
  if (John == John1) {
    cout << "The same" << endl;
  } else {
    cout << "Not same " << endl;
  }
}
