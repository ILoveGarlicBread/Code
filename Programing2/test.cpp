#include <iostream>
using namespace std;

class Circle {
  int radius;
public:
  Circle(){};
  Circle (int radius) { this->radius = radius; }
  Circle operator+(const Circle &other){
    Circle result(this->radius+other.radius);
    return result;
  }
  void describe() { cout << "Radius: " << radius << endl; }
};

template <class T> class Data {
private:
  T value1;
  T value2;

public:
  Data(T value1, T value2) {
    this->value1 = value1;
    this->value2 = value2;
  }
  T sum() { return value1 + value2; }
};

int main(){
  Data<int> intData(5, 10);
  cout << intData.sum() << endl;
  Circle circle1(5);
  Circle circle2(10);
  Data <Circle> circleData(circle1,circle2);
  Circle sumCircle=circleData.sum();
  sumCircle.describe();

  return 0;
}
