#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
int main() {
    printf ("������������ ������ � 2.1\
            \n������ �.�. ����-21 ");
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/home/");
    if (!dir) {
        perror("diropen");
        exit(1);
    };

    while ( (entry = readdir(dir)) != NULL) {
        printf("%d - %s [%d] %d\n",
            entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    };

    closedir(dir);
};
