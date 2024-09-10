#include <iostream>
using namespace std;
class Complex {
private:
  float real, imag;

public:
  void describe() { cout << real << " + " << imag << "i" << endl; }
  Complex() {}
  Complex(int input_real, int input_image)
      : real(input_real), imag(input_image) {}
  Complex(const Complex &other) : real(other.real), imag(other.imag) {}
  Complex operator+(const Complex &other) {
    Complex result;
    result.real = real + other.real;
    result.imag = imag + other.imag;
    return result;
  }
  bool operator==(const Complex &other) {
    return real == other.real && imag == other.imag;
  }
  void operator=(const Complex &other) {
    real = other.real;
    imag = other.imag;
  }
};
int main() {
  Complex a(1.0, 2.0), b(3.0, 4.0);
  a.describe();
  b.describe();
  Complex c = a + b;
  c.describe();
  cout << "Comparison between a and b: " << (a == b) << endl;
  Complex d = a;
  cout << "Comparison between a and d: " << (a == d) << endl;
  a = b;
  cout << "Comparison between a and d: " << (a == d) << endl;
  cout << endl;
  return 0;
}
