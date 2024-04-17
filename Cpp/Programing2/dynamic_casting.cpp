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

class Circle : public Shape {
  int radius;

public:
  Circle(int radius) : radius(radius){};
  float area() { return 3.1415 * radius * radius; }
};
class Canvas {
  vector<Shape *> shapes;

public:
  Canvas() {}
  void addShape(Shape *shape) { shapes.push_back(shape); }
  vector<Square *> getSquares() {
    vector<Square *> squares;     // Initialize empty vector to store squares
    for (Shape *shape : shapes) { // Iterate over all shapes in Canvas object
      Square *square = dynamic_cast<Square *>(
          shape);   // Try to cast Shape object to Square object
      if (square) { // If the cast is successful, add the square to the vector

        squares.push_back(square);
      }
    }
    return squares; // Return the vector of squares
  }
  void shapescounts() {
    int squareCount = 0;
    int circleCount = 0;
    int triangleCount = 0;
    for (Shape *shape : shapes) {
      if (dynamic_cast<Square *>(shape)) {
        squareCount++;
      }
    }
    for (Shape *shape : shapes) {
      if (dynamic_cast<Circle *>(shape)) {
        circleCount++;
      }
    }
    for (Shape *shape : shapes) {
      if (dynamic_cast<Triangle *>(shape)) {
        triangleCount++;
      }
    }
    cout << "Numbe of Squares: " << squareCount << endl;
    cout << "Numbe of Circles: " << circleCount << endl;
    cout << "Numbe of Triangle: " << triangleCount << endl;
  }
};
int main() {
  Square s(10);
  Triangle t(10, 5);
  Triangle t1(3, 4);
  Square s1(20);
  Square s2(30);
  Circle c(5);

  int count = 0;
  Canvas canvas;
  canvas.addShape(&s);
  canvas.addShape(&t);
  canvas.addShape(&t1);
  canvas.addShape(&s1);
  canvas.addShape(&s2);
  canvas.addShape(&c);
  canvas.shapescounts();
  cout << endl;
  return 0;
}
