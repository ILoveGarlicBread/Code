// C++ Program to Demonstrate
// Operator Overloading
#include <iostream>
using namespace std;

class Complex {
  int real, imag;

public:
  Complex() {}
  Complex(int r, int i) {
    real = r;
    imag = i;
  }
  Complex(const Complex &obj) {
    real = obj.real;
    imag = obj.imag;
  }

  Complex operator+(Complex const &obj) {
    Complex res;
    res.real = real + obj.real;
    res.imag = imag + obj.imag;
    return res;
  }
  bool operator==(Complex const &obj) {
    if (real == obj.real && imag == obj.imag)
      return true;
    else
      return false;
  }
  Complex operator=(Complex const &obj) {
    Complex res;
    res.real = obj.real;
    res.imag = obj.imag;
    return res;
  }
  void printnum() { cout << real << " + i" << imag << '\n'; }
};

int main() {
  Complex c1(10, 5), c2(2, 4);
  Complex c3 = c1 + c2;
  Complex c4 = c1;
  c3.printnum();
  c4.printnum();
  cout << endl;
  return 0;
}
