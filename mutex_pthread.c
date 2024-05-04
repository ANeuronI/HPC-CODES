#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define NUM_THREADS 5


pthread_mutex_t mutex;
int counter = 0;


void *thread_function(void *arg) {
    int i, thread_id;
    thread_id = *((int*)arg);


    for (i = 0; i < 3; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Thread %d: Counter value: %d\n", thread_id, counter);
        pthread_mutex_unlock(&mutex);
    }


    pthread_exit(NULL);
}


int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;


    pthread_mutex_init(&mutex, NULL);


    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }


    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }


    pthread_mutex_destroy(&mutex);


    return 0;
}
