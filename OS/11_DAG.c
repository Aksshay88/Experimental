#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>
struct tree_element
{
    char name[20];
    int x, y, ftype, lx, rx, nc, level;
    struct tree_element *link[5];
};
typedef struct tree_element node;
typedef struct
{
    char from[20];
    char to[20];
} link;
link L[10];
int nofl;
node *root;
void main()
{
    int gd = DETECT, gm;
    root = NULL;
    clrscr();
    create(&root, 0, "root", 0, 639, 320);
    read_links();
    clrscr();
    initgraph(&gd, &gm, "c:\\tc\\BGI");
    draw_link_lines();
    display(root);
    getch();
    closegraph();
}
void read_links()
{
    int i;
    printf("How many links: ");
    scanf("%d", &nofl);
    for (i = 0; i < nofl; i++)
    {
        printf("File/dir: ");
        fflush(stdin);
        gets(L[i].from);
        printf("User name: ");
        fflush(stdin);
        gets(L[i].to);
    }
}
void draw_link_lines()
{
    int i, x1, y1, x2, y2;
    for (i = 0; i < nofl; i++)
    {
        search(root, L[i].from, &x1, &y1);
        search(root, L[i].to, &x2, &y2);
        setcolor(LIGHTGREEN);
        setlinestyle(3, 0, 1);
        line(x1, y1, x2, y2);
        setcolor(YELLOW);
        setlinestyle(0, 0, 1);
    }
}
void search(node *root, char *s, int *x, int *y)
{
    int i;
    if (root != NULL)
    {
        if (strcmpi(root->name, s) == 0)
        {
            *x = root->x;
            *y = root->y;
            return;
        }
        else
        {
            for (i = 0; i < root->nc; i++)
                search(root->link[i], s, x, y);
        }
    }
}
void create(node **root, int lev, char *dname, int lx, int rx, int x)
{
    int i, gap;
    if (*root == NULL)
    {
        (*root) = (node *)malloc(sizeof(node));
        printf("Enter name of dir/file (under %s): ", dname);
        fflush(stdin);
        gets((*root)->name);
        printf("Enter 1 for dir/ 2 for file: ");
        scanf("%d", &(*root)->ftype);
        (*root)->level = lev;
        (*root)->y = 50 + lev * 50;
        (*root)->x = x;
        (*root)->lx = lx;
        (*root)->rx = rx;
        for (i = 0; i < 5; i++)
            (*root)->link[i] = NULL;
        if ((*root)->ftype == 1)
        {
            printf("No of sub directories / files (for %s): ", (*root)->name);
            scanf("%d", &(*root)->nc);
            if ((*root)->nc == 0)
                gap = rx - lx;
            else
                gap = (rx - lx) / (*root)->nc;
            for (i = 0; i < (*root)->nc; i++)
                create(&((*root)->link[i]), lev + 1, (*root)->name, lx + gap * i, lx + gap * i + gap, lx + gap * i + gap / 2);
        }
        else
            (*root)->nc = 0;
    }
}
/* displays the constructed tree in graphics mode */
void display(node *root)
{
    int i;
    settextstyle(2, 0, 4);
    settextjustify(1, 1);
    setfillstyle(1, BLUE);
    setcolor(14);
    if (root != NULL)
    {
        for (i = 0; i < root->nc; i++)
            line(root->x, root->y, root->link[i]->x, root->link[i]->y);
        if (root->ftype == 1)
            bar3d(root->x - 20, root->y - 10, root->x + 20, root->y + 10, 0, 0);
        else
            fillellipse(root->x, root->y, 20, 20);
        outtextxy(root->x, root->y, root->name);
        for (i = 0; i < root->nc; i++)
            display(root->link[i]);
    }
}