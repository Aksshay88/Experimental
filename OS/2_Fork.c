#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int pid;
    pid = fork();
    printf("\n THIS LINE EXECUTED TWICE");
    if (pid == -1)
    {
        printf("\n CHILD PROCESS NOT CREATED\n");
        exit(0);
    }
    if (pid == 0)
    {
        printf("\n I AM CHILD PROCESS AND MY ID IS %d \n", getpid());
        printf("\n THE CHILD PARENT PROCESS ID IS:%d \n", getppid());
    }
    else
    {
        printf("\n I AM PARENT PROCESS AND MY ID IS:%d\n", getpid());
        printf("\n THE PARENTS PARENT PROCESS ID IS:%d\n", getppid());
        printf("\n IT CAN BE EXECUTED TWICE");
        printf("\n");
    }
    return 0;
}