#include <stdio.h>
#include <string.h>
typedef struct CEO {
  char name[50];
  int Birthyear;
} CEO;

typedef struct Company {
  char name[50];
  CEO ceo;
} Company;

int main() 
{ 
  Company testcomany;
  strcpy(testcomany.name, "Test");
  strcpy(testcomany.ceo.name, "Dude");
  testcomany.ceo.Birthyear = 2000;
  



  return 0; 
}
