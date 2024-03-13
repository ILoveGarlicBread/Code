#include <stdio.h>
#include <math.h>
float function1(float x)
{
  float result= (x/2) * (1 + x + (0.04 *x*x*x));
  return result ;
}
float function2(float n)
{
  float result=0;
  for (int i = 1; i <= n; i++) {
        result += (-pow(0.5, i)) / i;
    }
  return result ;
}
int main()
{
  float x = 0.5;
  int n = 100;
  float result=function1(x);
  printf("%f\n", result);
  float result2= function2(n);
  printf("%f\n", result2);





  return 0;
}
