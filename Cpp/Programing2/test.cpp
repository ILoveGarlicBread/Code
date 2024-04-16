#include <iostream>
using namespace std;

class Square {
  int side;

public:
  Square(int s) { this->side = s; }
  int getArea() { return side * side; }
};

class Rectangle {
  int width, height;

public:
  Rectangle(int w, int h) {
    this->width = w;
    this->height = h;
  }
  int getArea() { return width * height; }
};

class Canvas {
public:
  void showArea(Square *s) {
    cout << "Area of Square: " << s->getArea() << endl;
  };
  void showArea(Rectangle *r) {
    cout << "Area of Rectangle: " << r->getArea() << endl;
  };
};

int main() {
  Square s(5);
  Rectangle r(4, 3);
  Canvas canvas;
  canvas.showArea(&s);
  canvas.showArea(&r);
  cout << endl;
  return 0;
}
