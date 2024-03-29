#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int pid, i;
    pid = fork();
    printf("\n THIS LINE EXECUTED TWICE");
    if (pid == -1)
    {
        printf("\n CHILD PROCESS NOT CREATED\n");
        exit(0);
    }
    if (pid == 0)
    {
        printf("\n CHILD PROCESS IS IN PROGRESS\n");
        for (i = 0; i < 5; i++)
            printf("\n THE CHILD PROCESSING VALUE IS:%d \n", i);
        execvp("ls", argv);
    }
    else
    {
        printf("\n PARENT PROCESS IS IN WAITING\n");
        printf("\n CHILD PROCESS COMPLETED ITS TASK\n");
    }
    exit(0);
}