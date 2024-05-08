#include <iostream>
using namespace std;
class Manufacturer {
  int id;
  string location;

public:
  Manufacturer() {}
  Manufacturer(int id, string location) : id(id), location(location) {}
  void describe() {
    cout << "Manufaturer ID: " << id << endl
         << "Location: " << location << endl;
  }
};
class Device {
  string name;
  double price;
  Manufacturer Manufaturer;

public:
  Device(string name, double price, int id, string location) {
    this->name = name;
    this->price = price;
    this->Manufaturer = Manufacturer(id, location);
  }
  void describe() {
    cout << "Name: " << name << endl << "Price: " << price << endl;
    Manufaturer.describe();
  }
};
class anotherManufacturer {
  int id;
  string location;

public:
  anotherManufacturer() {}
  anotherManufacturer(int id, string location) : id(id), location(location) {}
  void describe() {
    cout << "Manufaturer ID: " << id << endl
         << "Location: " << location << endl;
  }
};

class anotherDevice {
  string name;
  double price;
  anotherManufacturer *anothermanufacturer;

public:
  anotherDevice(string name, double price, int id, string location) {
    this->name = name;
    this->price = price;
    this->anothermanufacturer = new anotherManufacturer(id, location);
  }
  ~anotherDevice() { delete anothermanufacturer; }
  void describe() {
    cout << "Name: " << name << endl << "Price: " << price << endl;
    anothermanufacturer->describe();
  }
};
int main() {
  Device device0("device0", 10, 1234, "location0");
  device0.describe();
  anotherDevice device1("device1", 20, 5678, "locaiton1");
  device1.describe();
  return 0;
}
