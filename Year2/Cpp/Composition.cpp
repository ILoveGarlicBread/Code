#include <iostream>
using namespace std;

class A {
private:
    int a;

public:
    void setValue(int b) {
        a = b;
    }

    void getSum(int c) {
        cout << "Sum of " << a << " and " << c << " = " << a + c << endl;
    }
};
class B {
public:
    A x;
    void showResult() {
        x.getSum(10);
    }
};

int main() {
    B obj1;
    obj1.x.setValue(10);
    obj1.x.getSum(50);
    obj1.showResult();
}
