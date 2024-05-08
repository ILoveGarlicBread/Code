#include <iostream>
using namespace std;

class Product {
  float price;
  float weight;
  float discount;

public:
  Product() : price(0), weight(0), discount(0){};
  Product(float inputPrice, float inputWeight, float inputDiscount) {
    this->price = inputPrice;
    this->weight = inputWeight;
    this->discount = inputDiscount;
  }
  Product(Product &anotherProduct) {
    anotherProduct.price = this->price;
    anotherProduct.weight = this->weight;
    anotherProduct.discount = this->discount;
  }
  Product operator+(Product const &other) {
    Product result;
    result.price = this->price + other.price;
    result.weight = this->weight + other.weight;
    result.discount = this->discount + other.discount;
    return result;
  }

  void operator=(Product const &other) {
    this->price = other.price;
    this->weight = other.weight;
    this->discount = other.discount;
  }

  bool operator==(Product const &other) {
    return (this->price == other.price && this->weight == other.weight &&
            this->discount == other.discount)
               ? true
               : false;
  }

  void describe() {
    cout << "Price: " << price << endl
         << "Weight: " << weight << endl
         << "Discount: " << discount << endl
         << endl;
  }
};

int main() {
  Product product1;
  product1.describe();
  Product product2(10.5, 2.5, 1.2);
  product2.describe();
  Product product3(15, 2.2, 0.5);
  product3.describe();
  Product product4(product1);
  product4 = product2 + product3;
  cout << "Is product 4 = product 2: " << (product4 == product2) << endl;
  product4 = product2;
  cout << endl;
  product4.describe();
  cout << "Is product 4 = product 2: " << (product4 == product2) << endl;
  return 0;
}
