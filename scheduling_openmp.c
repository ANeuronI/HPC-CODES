#include <stdio.h>
#include <omp.h>

#define NUM_ITERATIONS 5
#define NUM_THREADS 4

int main() {
    int i;

    printf("Default Loop Scheduling:\n");
    #pragma omp parallel for
    for (i = 0; i < NUM_ITERATIONS; i++) {
        printf("Thread %d handles iteration %d\n", omp_get_thread_num(), i);
    }

    printf("\nStatic Loop Scheduling:\n");
    #pragma omp parallel for schedule(static)
    for (i = 0; i < NUM_ITERATIONS; i++) {
        printf("Thread %d handles iteration %d\n", omp_get_thread_num(), i);
    }

    printf("\nDynamic Loop Scheduling:\n");
    #pragma omp parallel for schedule(dynamic)
    for (i = 0; i < NUM_ITERATIONS; i++) {
        printf("Thread %d handles iteration %d\n", omp_get_thread_num(), i);
    }

    return 0;
}
