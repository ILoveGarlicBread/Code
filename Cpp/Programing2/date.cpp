#include <iostream>
using namespace std;

class Date {
public:
  int day, month, year;
  Date(int input_date, int input_month, int input_year)
      : day(input_date), month(input_month), year(input_year){};
  void sumdate(Date input_date) {
    day = day + input_date.day;
    month = month + input_date.month;
    year = year + input_date.year;
    while (day > 30) {
      day = day - 30;
      month = month + 1;
    }
    while (month > 12) {
      month = month - 12;
      year = year + 1;
    }
  }
};

int main() {
  Date d1(10, 10, 2020);
  Date d2(20, 20, 2020);
  d1.sumdate(d2);
  cout << d1.day << " " << d1.month << " " << d1.year << endl;
  return 0;
}
