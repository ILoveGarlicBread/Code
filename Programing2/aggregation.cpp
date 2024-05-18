// Aggregation is a special form of association.
// It is a relationship between two classes like association,
// however its a directional association, which means it is strictly
// a one way association. It represents a "whole-part" relationship.
// In aggregation, the child can exist independently of the parent.
// For example, consider two classes, "Manufacturer" and "Device".
// Here, a manufacturer can produce multiple devices.
// So, the relationship between the two classes is aggregation.
// The manufacturer can exist without a device.
// Similarly, a device can exist without a manufacturer.
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
  // Name: device0
  // Price: 10
  // Manufaturer ID: 1234
  // Location: location0

  anotherDevice device1("device1", 20, 5678, "locaiton1");
  device1.describe();
  // Name: device1
  // Price: 20
  // Manufaturer ID: 5678
  // Location: locaiton1

  return 0;
}
