#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 2
pthread_t tid[NUM_THREADS];
int counter = 0;
pthread_mutex_t lock;
void *doSomeThing(void *arg)
{
    unsigned long i;
    pthread_mutex_lock(&lock);
    counter++;
    printf("\nJob %d started\n", counter);
    pthread_mutex_unlock(&lock);
    for (i = 0; i < (0xFFFFFFFF); i++)
        ;
    pthread_mutex_lock(&lock);
    printf("\nJob %d finished\n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}
int main(void)
{
    int i;
    int err;
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\nmutex initialization failed\n");
        return 1;
    }
    for (i = 0; i < NUM_THREADS; i++)
    {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread: %s\n", strerror(err));
    }
    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}