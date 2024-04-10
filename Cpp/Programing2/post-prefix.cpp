#include <iostream>
using namespace std;

class Counter {
private:
  int count;

public:
  Counter(int c = 0) : count(c) {}
  Counter &operator++() {
    ++count;
    return *this;
  }
  Counter operator++(int) {
    Counter temp(count);
    count++;
    return temp;
  }
  int getCount() const { return count; }
};

int main() {
  Counter c(5);
  ++c;
  Counter a(5);
  Counter old_a = a++;
  cout << "c after prefix increment: " << c.getCount() << endl;
  cout << "a before increment: " << old_a.getCount() << endl;
  cout << "a after postfixe increment: " << a.getCount() << endl;
  return 0;
}
