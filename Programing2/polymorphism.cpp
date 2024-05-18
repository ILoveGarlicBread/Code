// Polymorphism in C++
#include <iostream>
using namespace std;
class Shape {
public:
  virtual float area() = 0;
};
class Square : public Shape {
  int side;

public:
  Square(int s) { this->side = s; }
  float area() { return side * side; }
};

class Rectangle : public Shape {
  int width, height;

public:
  Rectangle(int w, int h) {
    this->width = w;
    this->height = h;
  }
  float area() { return width * height; }
};
class Triangle : public Shape {
  int base, height;

public:
  Triangle(int b, int h) {
    this->base = b;
    this->height = h;
  }
  float area() { return 0.5 * base * height; }
};
class Canvas {
  Square *s;

public:
  Canvas(Square *s) : s(s) {}
  void describe() { cout << "Area: " << s->area() << endl; }
};

int main() {
  Square s(5);
  Rectangle r(4, 3);
  Triangle t(2, 3);
  Canvas canvas(&s);
  canvas.describe();
  // output: Area: 25
  cout << endl;
  return 0;
}
