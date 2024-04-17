#include <iostream>
#include <vector>
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
  vector<Shape *> shapes;

public:
  Canvas() {}
  void addShape(Shape *shape) { shapes.push_back(shape); }
  vector<Square *> getSquares() {
    vector<Square *> squares;
    for (Shape *shape : shapes) {
      Square *square = dynamic_cast<Square *>(shape);
      if (square) {
        squares.push_back(square);
      }
    }
    return squares;
  }
};

int main() {
  Square s(10);
  Triangle t(10, 5);
  Square s1(20);
  Square s2(30);

  int count = 0;
  Canvas canvas;
  canvas.addShape(&s);
  canvas.addShape(&t);
  canvas.addShape(&s1);
  canvas.addShape(&s2);
  vector<Square *> squares = canvas.getSquares();
  for (Square *square : squares) {
    count++;
  }
  cout << "Number of squares: " << count << endl;
  cout << endl;
  return 0;
}
