#include <iostream>
using namespace std;
class creativeName {
public:
  virtual void changevar() { cout << "Welcome" << endl; }
};
class evenlesscreativeName : public creativeName {
public:
  void changevar() { cout << "Hello" << endl; }
};
class name : public creativeName {
public:
  void changevar() { cout << "Bye" << endl; }
};
int main() {
  creativeName obj;
  obj.changevar();
  evenlesscreativeName obj1;
  obj1.changevar();
  name obj2;
  obj2.changevar();
  return 0;
}
