#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#define SEED time(NULL)
int count;
void *generatePoints(void *param){
  int n= *(int*)param;

  count = 0;
  for(int i = 0; i < n; ++i) {

    double x = (double)rand() / RAND_MAX;

    double y = (double)rand() / RAND_MAX;

    double z = x * x + y * y;

    if( z <= 1 ) count++;
  }
  pthread_exit(0);
}
int main() {

 srand( SEED );
 int n;
 printf("n = ");
 scanf("%d", &n);
pthread_t thread;
  pthread_create(&thread, NULL, generatePoints, &n );
  pthread_join(thread,NULL);


double pi = (double) count / n * 4;
 
 printf("Approximate PI = %g", pi);

 return(0);
}
