#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Point {
  int x, y;

public:
  Point(){};
  Point(int x, int y) : x(x), y(y) {}
  int getx() { return x; }
  int gety() { return y; }
};
class TwoDShape {
public:
  virtual double area() = 0;
  virtual double perimeter() = 0;
  Point center;
  float distance(TwoDShape &shape) {
    Point p1 = this->center;
    Point p2 = shape.center;
    return sqrt(pow(p1.getx() - p2.getx(), 2) + pow(p1.gety() - p2.gety(), 2));
  }
};
class Square : public TwoDShape {
  int side;

public:
  Square(int s, int x, int y) : side(s) { this->center = Point(x, y); }
  double area() { return side * side; }
  double perimeter() { return 4 * side; }
};

class Rectangle : public TwoDShape {
  int width, height;

public:
  Rectangle(int b, int h, int x, int y) : width(b), height(h) {
    this->center = Point(x, y);
  }
  double area() { return 0.5 * width * height; }
  double perimeter() { return 2 * (width + height); }
};

class Circle : public TwoDShape {
  int radius;

public:
  Circle(int radius, int x, int y) : radius(radius) {
    this->center = Point(x, y);
  };
  double area() { return 3.14 * radius * radius; }
  double perimeter() { return 2 * 3.14 * radius; }
};
void sortPerimeters(vector<pair<double, TwoDShape *>> &perimeters) {
  int n = perimeters.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      // If current perimeter is less than the next perimeter, swap them
      if (perimeters[j].first < perimeters[j + 1].first) {
        swap(perimeters[j], perimeters[j + 1]);
      }
    }
  }
}

int main() {
  Square s(10, 0, 0);
  Rectangle t(5, 10, 3, 3);
  Circle c(7, 2, 8);
  cout << "Distance between Square and Rectangle: " << s.distance(t) << endl;
  cout << "Area and Perimeter of Circle: " << c.area() << " " << c.perimeter()
       << endl;
  vector<TwoDShape *> listofshapes;
  listofshapes.push_back(&s);
  listofshapes.push_back(&t);
  listofshapes.push_back(&c);
  double totalArea = 0;
  for (TwoDShape *shape : listofshapes) {
    cout << "Area: " << shape->area() << endl;
    totalArea += shape->area();
  }
  cout << "Total Area: " << totalArea << endl;
  vector<pair<double, TwoDShape *>> perimeters;
  for (TwoDShape *shape : listofshapes) {
    perimeters.push_back(make_pair(shape->perimeter(), shape));
  }

  // Sort perimeters in decreasing order using custom sort function
  sortPerimeters(perimeters);

  // Print perimeters in decreasing order
  cout << "Perimeters in decreasing order:" << endl;
  for (const auto &perimeter_shape : perimeters) {
    cout << "Perimeter: " << perimeter_shape.first << endl;
  }
  cout << endl;
  return 0;
}
