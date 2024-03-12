#include <iostream>

int main() {
  int number;
  unsigned long long factorial = 1;

  std::cout << "Enter a positive integer: ";
  std::cin >> number;

  // Compute factorial using a for loop
  for (int i = 1; i <= number; ++i) {
    factorial *= i;
  }

  std::cout << "Factorial of " << number << " = " << factorial << std::endl;

  return 0;
}
