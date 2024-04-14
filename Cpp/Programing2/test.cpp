#include <iostream>
using namespace std;
int main() {
  int a = 10;
  int *pointer;
  pointer = &a;
  cout << "Address of a: " << pointer << endl;
}
