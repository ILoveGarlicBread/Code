#include <iostream>
#include <memory>
#include <string>
using namespace std;
class Bird {
protected:
  string name;
  string food;
  virtual void fly() = 0;
  virtual void eat() = 0;
  virtual void swim() = 0;

private:
  string conspiracy =
      "Birds are actually robots created by the government for spying";
};
class FlyingBird : public Bird {
public:
  void fly() { cout << name << " can fly" << endl; }
  void eat() { cout << name << " can eat " << food << endl; }
  void swim() { cout << name << " can not swim" << endl; }
};
class LandBird : public Bird {
public:
  void fly() { cout << name << " can not fly" << endl; }
  void eat() { cout << name << " can eat " << food << endl; }
  void swim() { cout << name << " can not swim" << endl; }
};
class SwimmingBird : public Bird {
public:
  void fly() { cout << name << " can not fly" << endl; }
  void eat() { cout << name << " can eat " << food << endl; }
  void swim() { cout << name << " can swim" << endl; }
};

class Pigeon : public FlyingBird {
public:
  Pigeon(string name, string food) {
    this->name = name;
    this->food = food;
  }
};

class Duck : public SwimmingBird {
public:
  Duck(string name, string food) {
    this->name = name;
    this->food = food;
  }
};
int main() {
  unique_ptr<Bird> bird1 = make_unique<Pigeon>("Pigeon", "seeds");
  unique_ptr<Bird> bird2 = make_unique<Duck>("Duck", "insects");
  bird1->fly();
  bird2->fly();
  bird1->eat();
  bird2->eat();
  cout << endl;
  return 0;
}
