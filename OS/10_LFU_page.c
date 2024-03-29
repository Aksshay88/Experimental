#include <stdio.h>
int n;
int findmax(int a[])
{
    int max, i, k = 0;
    max = a[0];
    for (i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            return k;
        }
        max = a[i];
        k = i;
    }
}
int main()
{
    int seq[30], fr[5], pos[5], find, flag, max, i, j, m, k, t, s, pf = 0;
    int count = 1, p = 0;
    float pfr;
    printf("ENTER MAX LIMIT OF THE SEQUENCE:");
    scanf("%d", &max);
    printf("ENTER THE SEQUENCE:");
    for (i = 0; i < max; i++)
        scanf("%d", &seq[i]);
    printf("ENTER THE NO OF FRAMES:");
    scanf("%d", &n);
    fr[0] = seq[0];
    pf++;
    printf("%d\t", fr[0]);
    i = 1;
    while (count < n)
    {
        flag = 1;
        p++;
        for (j = 0; j < i; j++)
        {
            if (seq[i] == seq[j])
                flag = 0;
        }
        if (flag != 0)
        {
            fr[count] = seq[i];
            printf("%d\t", fr[count]);
        }
        i++;
        count++;
        pf++;
        printf("\n");
    }
    for (i = p; i < max; i++)
    {
        flag = 1;
        for (j = 0; j < n; j++)
        {
            if (seq[i] == fr[j])
                flag = 0;
        }
        if (flag != 0)
        {
            for (j = 0; j < n; j++)
            {
                m = fr[j];
                for (k = i; k < max; k++)
                {
                    if (seq[k] == m)
                    {
                    }
                    else
                        pos[j] = k;
                    break;
                }
                pos[j] = -1;
            }
            for (k = 0; k < n; k++)
            {
                if (pos[k] == -1)
                    flag = 0;
            }
            if (flag != 0)
                s = findmax(pos);
            if (flag == 0)
            {
                for (k = 0; k < n; k++)
                {
                    if (pos[k] == -1)
                    {
                        pf++;
                        fr[s] = seq[i];
                        s = k;
                        break;
                    }
                }
            }
            for (k = 0; k < n; k++)
                printf("%d\t", fr[k]);
            printf("\n");
        }
    }
    pfr = (float)pf / (float)max;
    printf("\n THE NO.OF PAGE FAULTS ARE:%d", pf);
    printf("\n PAGE FAULT RATE:%f", pfr);
    return 0;
}