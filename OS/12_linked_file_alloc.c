#include <stdio.h>
void main()
{
    char a[10];
    int i, sb, eb, fb1[10];
    printf("\nEnter the file name: ");
    scanf("%s", a);
    printf("Enter the starting block: ");
    scanf("%d", &sb);
    printf("Enter the ending block: ");
    scanf("%d", &eb);
    // Prompt user for free blocks
    printf("Enter 5 free blocks: ");
    for (i = 0; i < 5; i++)
    {
        printf("Enter the free block %d: ", i + 1);
        scanf("%d", &fb1[i]);
    }
    // Print file information
    printf("\nFile name \tStarting block \tEnding block\n");
    printf("%s \t\t%d\t\t%d\n", a, sb, eb);
    // Print file utilization
    printf("\n%s File Utilization of Linked type of following blocks:\n", a);
    printf("%d->", sb);
    for (i = 0; i < 5; i++)
    {
        printf("%d->", fb1[i]);
    }
    printf("%d\n", eb);
}