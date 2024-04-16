#include <iostream>

#include <vector>
using namespace std;

void print_vector(const vector<int> &v) {
  for (const int &i : v) {
    cout << i << "  ";
  }
  cout << endl;
}
int main() {
  vector<int> v = {1, 2, 3, 4, 5};
  print_vector(v);
  // Add element at the end
  v.push_back(6);
  print_vector(v);
  // Access elements
  cout << "Element at index 2: " << v.at(2) << endl;
  // Modify elements
  cout << "Modify element at index 0" << endl;
  v.at(0) = 0;
  print_vector(v);
  // remove the last element
  v.pop_back();
  print_vector(v);
  // size(), capacity()
  cout << "Size of vector: " << v.size() << endl;
  cout << "Capacity of vector: " << v.capacity() << endl;
  // front(), back()
  cout << "First and last element in vector: " 
       << v.front() << " & " << v.back()
       << endl;
  cout << endl;
  return 0;
}
