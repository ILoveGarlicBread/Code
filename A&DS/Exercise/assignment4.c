#include <stdio.h>
#include <string.h>
struct Data {
  int id;
  char name[50];
  int age;
  float salary;
};

void getemployee(struct Data *pointer, int id, char *name, int age,
                 float salary) {
  pointer->id = id;
  strcpy(pointer->name, name);
  pointer->age = age;
  pointer->salary = salary;
}

int main() {
  struct Data employee;
  struct Data *pointer = &employee;

  printf("\n");
  return 0;
}
