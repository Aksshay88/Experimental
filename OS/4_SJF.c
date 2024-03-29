#include <stdio.h>
void main()
{
    int i, j, t, n, stt = 0, pid[10], at[10], bt[10], ft[10], att, wt[10], ta[10], totwt = 0, totta = 0;
    float avgwt, avgta;
    printf("ENTER THE NUMBER OF PROCESSES:");
    scanf("%d", &n);
    printf("\nENTER THE ARRIVAL TIME:");
    scanf("%d", &att);
    for (i = 1; i <= n; i++)
    {
        pid[i] = i;
        at[i] = att;
        printf("\nENTER THE BURST TIME FOR PROCESS %d:", i);
        scanf("%d", &bt[i]);
    }
    // Sorting processes based on burst time
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;
                t = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = t;
            }
        }
    }
    stt = att;
    for (i = 1; i <= n; i++)
    {
        ft[i] = stt + bt[i];
        wt[i] = stt - at[i];
        ta[i] = ft[i] - at[i];
        totta += ta[i];
        totwt += wt[i];
        stt = ft[i];
    }
    avgwt = (float)totwt / n;
    avgta = (float)totta / n;
    printf("\nPNO\tARRIVAL TIME\tBURST TIME\tCOMPLETION TIME\tWAIT TIME\tTAT\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], ft[i], wt[i], ta[i]);
    }
    printf("\nAVERAGE TURN AROUND TIME = %f", avgta);
    printf("\nAVERAGE WAITING TIME = %f\n", avgwt);
}