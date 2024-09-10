
#include <iostream>
using namespace std;
class ID {
  int id;

public:
  ID(){};
  ID(int id) : id(id) {}
  void describe() { cout << id << endl; }
};

class Student0 {
  string name;
  int id;

public:
  Student0(string name, int id) : name(name), id(id) {}
  void describe() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
  }
};
class Student1 {
  string name;
  ID id;

public:
  Student1(string name, ID id) : name(name), id(id) {}
  void describe() {
    cout << "Name: " << name << endl;
    cout << "ID: ";
    id.describe();
  }
};
class Student2 {
  string name;
  ID *id;

public:
  Student2(string name, ID *id) {
    this->name = name;
    this->id = id;
  }
  void describe() {
    cout << "Name: " << name << endl;
    cout << "ID: ";
    id->describe();
  }
};

class Student3 {
  string name;
  ID id;

public:
  Student3(string name, int id) {
    this->name = name;
    this->id = ID(id);
  }
  void describe() {
    cout << "Name: " << name << endl;
    cout << "ID: ";
    id.describe();
  }
};
class Student4 {
  string name;
  ID &id;

public:
  Student4(string name, ID &id) : name(name), id(id) {}
  void describe() {
    cout << "Name: " << name << endl;
    cout << "ID: ";
    id.describe();
  }
};
int main() {
  Student0 s0("John", 1);
  s0.describe();
  ID id0(2);
  Student1 s1("Liam", id0);
  s1.describe();
  ID id1(3);
  Student2 s2("Emma", &id1);
  s2.describe();
  Student3 s3("Olivia", 4);
  s3.describe();
  ID id4(5);
  Student4 s4("Noah", id4);
  s4.describe();
}
