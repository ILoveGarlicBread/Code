#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 3
int buffer[SIZE];

sem_t empty,full;

int *fib_seq;
int in,out; 
int count;

void* generate_fibonacci(void* arg) {
    while(in<count){
        sem_wait(&empty);
        if(in<2){
            buffer[in]= 1;
        }else{
            buffer[in % SIZE]= buffer[(in-1) % SIZE] + buffer[(in-2) % SIZE];
        }
        in++;
        sem_post(&full);
    }
}
int main(){
    int count;
    int in = 0;
    int out= 0;
    printf("Enter the number of Fibonacci sequence: ");
    scanf("%d ",&count);
    pthread_t pid;
    pthread_create(&pid, NULL, generate_fibonacci, NULL);
    while (out < count) {
        sem_wait(&full);
        printf("%d ", buffer[out % SIZE]);
        out++;
        sem_post(&empty);
    }
}


    
