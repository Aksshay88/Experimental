#include <stdio.h>
#include <conio.h>
#include <string.h>
int n;
void main()
{
    int b[20], b1[20], i, j, blocks[20][20], sz[20];
    char F[20][20], S[20], ch;
    clrscr();
    printf("\nEnter no. of Files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter file %d name: ", i + 1);
        scanf("%s", &F[i]);
        printf("\nEnter file %d size (in kb): ", i + 1);
        scanf("%d", &sz[i]);
        printf("\nEnter blocksize of File %d (in bytes): ", i + 1);
        scanf("%d", &b[i]);
    }
    for (i = 0; i < n; i++)
    {
        b1[i] = (sz[i] * 1024) / b[i];
        printf("\n\nEnter blocks for file %d", i + 1);
        for (j = 0; j < b1[i]; j++)
        {
            printf("\nEnter the %d block: ", j + 1);
            scanf("%d", &blocks[i][j]);
        }
    }
    do
    {
        printf("\nEnter the Filename: ");
        scanf("%s", &S);
        for (i = 0; i < n; i++)
        {
            if (strcmp(F[i], S) == 0)
            {
                printf("\nFname\tFsize\tBsize\tNblocks\tBlocks\n");
                printf("\n\t\n");
                printf("\n%s\t%d\t%d\t%d\t", F[i], sz[i], b[i], b1[i]);
                for (j = 0; j < b1[i]; j++)
                    printf("%d->", blocks[i][j]);
            }
        }
        printf("\n-\n");
        printf("\nDo you want to continue? (Y: yes / n: no): ");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch != 'n');
}