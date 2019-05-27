#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <dirent.h>


int main()
{
    printf("лабораторная работа 2. Алиуллин. ИСТбд-21\n");
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/");///открывает поток информации для директории
    if (!dir) {
        perror("diropen");///выводит ошибку
        exit(1);
    };

    while ( (entry = readdir(dir)) != NULL) {
        printf("%lu - %s [%d]\n",entry->d_ino, entry->d_name, entry->d_type);
    };

    closedir(dir);
}
