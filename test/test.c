#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "boolean.h"

struct stat info;

int main()
{
    char *path = "/home/azzmi/projects/Tubes-Alstrukdat/compile.sh";
    // if (stat(path, &info) != 0)
    //     printf("cannot access %s\n", path);
    // else if (info.st_mode & __S_IFDIR)
    //     printf("%s is a directory\n", path);
    // else
    //     printf("%s is no directory\n", path);

    if (stat(path, &info) != 0 || !(info.st_mode & __S_IFDIR)) {
        printf("Folder tidak ada. Folder akan dibuat...");
        // mkdir(path);
    }

    return 0;
}