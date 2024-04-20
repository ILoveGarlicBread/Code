#include <iostream>
using namespace std;

class Employee {
  string name;
  int id;
  string gender;
  int departmentID;

public:
  Employee(){};

  Employee(string name, int id, string gender, int departmentID) {
    this->name = name;
    this->id = id;
    this->gender = gender;
    this->departmentID = departmentID;
  }

  int getID() { return id; }
  string getName() { return name; }
  int getDepartmentID() { return departmentID; }
  string getgender() { return gender; }

  void setID(int id) { this->id = id; }
  void setName(string name) { this->name = name; }
  void setDepartmentID(int departmentID) { this->departmentID = departmentID; }
  void setgender(string gender) { this->gender = gender; }

  void describe() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Gender: " << gender << endl;
    cout << "Department ID: " << departmentID << endl;
  }
};
class Manager : public Employee {
public:
  Manager(string name, int id, string gender, int departmentID){};
  void describe() {
    cout << "Manager" << endl;
    Employee::describe();
  }
};

int main() {
  Employee John("John", 1234, "Male", 2);
  Manager Jane("Jane", 5678, "Female", 1);
  John.describe();
  Jane.describe();
  cout << endl;
  return 0;
}
