#include <stdio.h>
#include <omp.h>

int main() {

    omp_set_num_threads(3);
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();

        // Task 1: Print thread number and its task
        #pragma omp task
        {
            printf("Thread %d: Task 1\n", thread_id);
        }

        // Task 2: Print thread number and its task
        #pragma omp task
        {
            printf("Thread %d: Task 2\n", thread_id);
        }

        // Task 3: Print thread number and its task
        #pragma omp task
        {
            printf("Thread %d: Task 3\n", thread_id);
        }
    }

    return 0;
}
