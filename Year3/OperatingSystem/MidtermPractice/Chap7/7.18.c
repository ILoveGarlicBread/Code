#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define NUM_POINTS 400000000 // Total points to generate

int main() {
    int count_in_circle = 0; // Shared variable for points within the circle
    unsigned int seed = time(NULL); // Seed for random number generator

    // Start parallel region with reduction clause
    #pragma omp parallel for reduction(+:count_in_circle) private(seed)
    for (int i = 0; i < NUM_POINTS; i++) {
        double x = (double)rand_r(&seed) / RAND_MAX; // Random x
        double y = (double)rand_r(&seed) / RAND_MAX; // Random y

        if (x * x + y * y <= 1) {
            count_in_circle++; // Increment if point is inside the circle
        }
    }

    // Calculate Pi
    double pi_estimate = 4.0 * (double)count_in_circle / NUM_POINTS;
    printf("Estimated value of Pi = %f\n", pi_estimate);

    return 0;
}

