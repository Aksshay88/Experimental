#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define num_loops 5
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};
int main(int argc, char *argv[])
{
    int semset_id;
    union semun sem_val;
    int child_pid;
    int i;
    struct sembuf sem_op;
    int rc;
    struct timespec delay;
    semset_id = semget(IPC_PRIVATE, 1, 0600);
    if (semset_id == -1)
    {
        perror("semget");
        exit(1);
    }
    printf("SEMAPHORE SET CREATED SEMAPHORE SET ID %d\n", semset_id);
    sem_val.val = 0;
    rc = semctl(semset_id, 0, SETVAL, sem_val);
    child_pid = fork();
    switch (child_pid)
    {
    case -1:
        perror("fork");
        exit(1);
    case 0: // Consumer process
        for (i = 0; i < num_loops; i++)
        {
            sem_op.sem_num = 0;
            sem_op.sem_op = -1;
            sem_op.sem_flg = 0;
            semop(semset_id, &sem_op, 1);
            printf("Consumer consumed item %d\n", i);
            fflush(stdout);
        }
        break;
    default: // Producer process
        for (i = 0; i < num_loops; i++)
        {
            // Simulate production time
            delay.tv_sec = 1;
            delay.tv_nsec = 0;
            nanosleep(&delay, NULL);
            sem_op.sem_num = 0;
            sem_op.sem_op = 1;
            sem_op.sem_flg = 0;
            semop(semset_id, &sem_op, 1);
            printf("Producer produced item %d\n", i);
            fflush(stdout);
        }
        break;
    }
    return 0;
}