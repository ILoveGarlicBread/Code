#include <iostream>
using namespace std;

class Square {
  int side;

public:
  Square(int side) { this->side = side; }
  Square(){};
  Square operator+(const Square &s) {
    Square result(this->side + s.side);
    return result;
  }
  Square operator*(const Square &s) {
    Square result(this->side * s.side);
    return result;
  }
  Square operator-(const Square &s) {
    Square result(this->side - s.side);
    return result;
  }
  void describe() { cout << "Side: " << side << endl; }
};
class Vector {
  int value1;
  int value2;

public:
  Vector(){};
  Vector(int value1, int value2) {
    this->value1 = value1;
    this->value2 = value2;
  }
  Vector operator+(const Vector &s) {
    Vector result(this->value1 + s.value1, this->value2 + s.value2);
    return result;
  }
  Vector operator*(const Vector &s) {
    Vector result(this->value1 * s.value1, this->value2 * s.value2);
    return result;
  }
  Vector operator-(const Vector &s) {
    Vector result(this->value1 - s.value1, this->value2 - s.value2);
    return result;
  }
  void describe() { cout << "(" << value1 << "," << value2 << ")" << endl; }
};

// int add(int a, int b) { return a + b; }
// double add(double a, double b) { return a + b; }
// string add(string a, string b) { return a + b; }
// Square add(Square a, Square b) { return a + b; }

// template <typename T> T add(T a, T b) { return a + b; }
// template <typename M> M multiply(M a, M b) { return a * b; }
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

int main() {
  Square s1(5), s2(10);
  //  Square s3 = add(s1, s2);
  //  s3.describe();
  //  Square s4 = multiply(s1, s2);
  //  s4.describe();

  Data<int> intData(5, 10);
  cout << "sum1: " << intData.sum() << endl;
  string str1 = "Hello, ";
  string str2 = "World!";
  Data<string> stringData(str1, str2);
  cout << "sum2: " << stringData.sum() << endl;
  Data<Square> squareData(s1, s2);
  Square sum3 = squareData.sum();
  sum3.describe();

  Vector v1(5, 10), v2(10, 20);
  Data<Vector> vectorData(v1, v2);
  Vector sum4 = vectorData.sum();
  sum4.describe();
  cout << endl;
  return 0;
}
