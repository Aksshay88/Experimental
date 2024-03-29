#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
void main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *rddir;
    printf("LISTING THE DIRECTORY CONTENT\n");
    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        printf("Unable to open directory\n");
        return;
    }
    printf("THE CURRENT DIRECTORY FILES ARE:\n");
    while ((rddir = readdir(dir)) != NULL)
    {
        printf("%s\n", rddir->d_name);
    }
    closedir(dir);
}