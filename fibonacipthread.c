
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define MAX 10


int fib_series[MAX];


void *calculate_fibonacci(void *param) {
    int *n = (int *)param;


    fib_series[0] = 0;
    fib_series[1] = 1;


    for (int i = 2; i < *n; i++) {
        fib_series[i] = fib_series[i - 1] + fib_series[i - 2];
    }


    pthread_exit(0);
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return -1;
    }


    int n = atoi(argv[1]);


    if (n > MAX) {
        printf("Number should be less than or equal to %d\n", MAX);
        return -1;
    }


    pthread_t tid;
    pthread_attr_t attr;


    pthread_attr_init(&attr);


    pthread_create(&tid, &attr, calculate_fibonacci, &n);
    pthread_join(tid, NULL);


    printf("Fibonacci Series:\n");


    for (int i = 0; i < n; i++) {
        printf("%d ", fib_series[i]);
    }


    printf("\n");


    return 0;}