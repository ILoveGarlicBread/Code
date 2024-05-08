#include <iostream>
#include <string>
using namespace std;
class Employee {
private:
  int ID;
  string name;
  int age;

public:
  string getname() { return name; }
  void setname(string input_name) { name = input_name; }
  int getID() { return ID; }
  void setID(int input_ID) { ID = input_ID; }
  int getage() { return age; }
  void setage(int input_age) { age = input_age; }
  void printinfo() {
    cout << getname() << "'s ID is " << getID() << " and " << getage()
         << " years old." << endl;
  }
  Employee(int input_ID) : ID(input_ID){};
  Employee(string input_name, int input_ID, int input_age) {
    name = input_name;
    ID = input_ID;
    age = input_age;
  }
  ~Employee() { cout << "Deleting allocated memory." << endl; }
};
int main() {
  Employee myemployee(1234);
  myemployee.setname("Brian");
  myemployee.setage(30);
  Employee myemployee1("Hannah", 5678, 25);
  myemployee.printinfo();
  myemployee1.printinfo();
  return 0;
}
