#include <stdio.h>
void main()
{
    int i, j, t, n, stt = 0, pid[10], pr[10], at[10], bt[10], ft[10], att;
    int wt[10], ta[10], totwt = 0, totta = 0;
    float avgwt, avgta;
    printf("ENTER THE NUMBER OF PROCESSES:");
    scanf("%d", &n);
    printf("\nENTER THE ARRIVAL TIME:");
    scanf("%d", &att);
    for (i = 1; i <= n; i++)
    {
        pid[i] = i;
        printf("\nENTER THE BURST TIME FOR PROCESS %d:", i);
        scanf("%d", &bt[i]);
        printf("\nENTER THE PRIORITY OF PROCESS %d:", i);
        scanf("%d", &pr[i]);
        at[i] = att;
    }
    // Sorting processes based on priority
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (pr[j] > pr[j + 1])
            {
                t = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = t;
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;
                t = pr[j];
                pr[j] = pr[j + 1];
                pr[j + 1] = t;
            }
        }
    }
    stt = att;
    for (i = 1; i <= n; i++)
    {
        ft[i] = stt + bt[i];
        wt[i] = stt - at[i];
        ta[i] = ft[i] - at[i];
        if (wt[i] < 0)
        {
            wt[i] = 0;
        }
        totwt += wt[i];
        totta += ta[i];
        stt = ft[i];
    }
    avgwt = (float)totwt / n;
    avgta = (float)totta / n;
    printf("\nPNO\tARR TIME\tBURST TIME\tFINISH TIME\tWAIT TIME\tTURN TIME\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ft[i], wt[i], ta[i]);
    }
    printf("\nTHE AVERAGE WAITING TIME IS: %f\n", avgwt);
    printf("THE AVERAGE TURNAROUND TIME IS: %f\n", avgta);
}