#include <stdio.h>
#include <omp.h>

#define NUM_STEPS 1000000000 

double f(double x) {
    return 4.0 / (1.0 + x * x); 
}

int main() {
    double step = 1.0 / NUM_STEPS; 
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < NUM_STEPS; i++) {
        double x = (i + 0.5) * step; 
        sum += f(x); 
    }

    double pi = step * sum; 

    printf("Approximation of Pi: %f\n", pi);

    return 0;
}
