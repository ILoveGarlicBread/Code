#include <iostream>
#include <string>
using namespace std;
class Person {
private:
  string name;
  int birthyear;

public:
  Person() {
    name = "Peter";
    birthyear = 2000;
  }
  Person(const Person &other) {
    name = other.name;
    birthyear = other.birthyear;
  }
  ~Person() { cout << "Object destroyed" << endl; }
  Person(string name, int birthyear) {
    this->name = name;
    this->birthyear = birthyear;
  }
  bool checkName(const Person &other) { return name == other.name; }
  bool checkBirthyear(const Person &other) {
    return birthyear == other.birthyear;
  }
  void printinfo() {
    cout << "Name: " << name << " born in " << birthyear << endl;
  }
};
int main() {
  Person Peter;
  Person Sarah("Sarah", 1999);
  Peter.printinfo();
  Sarah.printinfo();
  return 0;
}
