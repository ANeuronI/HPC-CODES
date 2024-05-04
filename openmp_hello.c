#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads;

    // Set number of threads to use
    omp_set_num_threads(4); // Set to the desired number of threads

    // Parallel region begins
    #pragma omp parallel
    {
        // Get the total number of threads
        num_threads = omp_get_num_threads();
        
        // Get the thread number
        int thread_id = omp_get_thread_num();

        // Print "Hello, World!" message
        printf("Hello, World! This is thread %d\n", thread_id);
    }
    // Parallel region ends

    // Print the number of threads created
    printf("Total threads created: %d\n", num_threads);

    return 0;
}
