#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SEED time(NULL)

int main() {
    srand(SEED);
    int n;

    printf("n = ");
    scanf("%d", &n);

    int count = 0;

    #pragma omp parallel
    {
        int private_count = 0; 
        #pragma omp for
        for (int i = 0; i < n; ++i) {
            double x = (double)rand() / RAND_MAX;
            double y = (double)rand() / RAND_MAX;
            double z = x * x + y * y;

            if (z <= 1) {
                private_count++;
            }
        }

        #pragma omp atomic
        count += private_count;
    }

    double pi = (double)count / n * 4;
    printf("Approximate PI = %g\n", pi);

    return 0;
}

