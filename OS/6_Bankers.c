#include <stdio.h>
#define MAX_PROCESSES 100
#define MAX_RESOURCES 100
int max[MAX_PROCESSES][MAX_RESOURCES];
int alloc[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int avail[MAX_RESOURCES];
int n, r;
void input();
void show();
void cal();
int main()
{
    printf("********** Deadlock Avoidance ************\n");
    input();
    show();
    cal();
    return 0;
}
void input()
{
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource instances: ");
    scanf("%d", &r);
    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the available Resources:\n");
    for (int j = 0; j < r; j++)
    {
        scanf("%d", &avail[j]);
    }
}
void show()
{
    printf("\nProcess\t Allocation\t Max\t Available\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t ", i + 1);
        for (int j = 0; j < r; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (int j = 0; j < r; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if (i == 0)
        {
            for (int j = 0; j < r; j++)
            {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}
void cal()
{
    int finish[MAX_PROCESSES] = {0};
    int flag;
    int work[MAX_RESOURCES];
    for (int i = 0; i < r; i++)
    {
        work[i] = avail[i];
    }
    int safeSequence[MAX_PROCESSES];
    int ssIndex = 0;
    do
    {
        flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == r)
                {
                    for (int k = 0; k < r; k++)
                    {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    flag = 1;
                    safeSequence[ssIndex++] = i;
                }
            }
        }
    } while (flag);
    int i;
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            break;
        }
    }
    if (i < n)
    {
        printf("\n\nSystem is in Deadlock and the Deadlock processes are:\n");
        for (int j = 0; j < n; j++)
        {
            if (finish[j] == 0)
            {
                printf("P%d\t", j + 1);
            }
        }
        printf("\n");
    }
    else
    {
        printf("\nNo Deadlock Occurs.\n");
        printf("Safe Sequence: ");
        for (int j = 0; j < n; j++)
        {
            printf("P%d ", safeSequence[j] + 1);
        }
        printf("\n");
    }
}