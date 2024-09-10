#include <iostream>
using namespace std;

class Beverage {
private:
  int price;
  int toppingPrice;
  int condimentPrice;

public:
  void describe() {
    cout << "Price: " << price << endl;
    cout << "Topping Price: " << toppingPrice << endl;
    cout << "Condiment Price: " << condimentPrice << endl;
    cout << "Total Price: " << price + toppingPrice + condimentPrice << endl;
    cout << endl;
  }
  Beverage() {
    price = 0;
    toppingPrice = 0;
    condimentPrice = 0;
  }
  Beverage(int price, int topingPrice, int condimentPrice) {
    this->price = price;
    this->toppingPrice = topingPrice;
    this->condimentPrice = condimentPrice;
  }
  Beverage operator+(const Beverage &other) {
    Beverage result;
    result.price = price + other.price;
    result.toppingPrice = toppingPrice + other.toppingPrice;
    result.condimentPrice = condimentPrice + other.condimentPrice;
    return result;
  }
  bool operator==(const Beverage &other) {
    return price == other.price && toppingPrice == other.toppingPrice &&
           condimentPrice == other.condimentPrice;
  }
};

int main() {
  Beverage wine(100, 10, 20);
  cout << "Wine:" << endl;
  wine.describe();
  Beverage beer(50, 5, 10);
  cout << "Beer:" << endl;
  beer.describe();
  Beverage cocktail = wine + beer;
  cout << "Cocktail:" << endl;
  cocktail.describe();
  cout << endl;
  Beverage water(100, 10, 20);
  cout << "Water:" << endl;
  water.describe();
  cout << "Is wine equal to water? " << (wine == water) << endl;

  return 0;
}
