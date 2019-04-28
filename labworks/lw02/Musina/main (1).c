#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

int main()
{
    printf("Мусина Наиля ИСТбд-21 \n");
    DIR *fd;
    struct dirent *d;//структура данных описывающая одну запись
    fd=opendir(".");//открытие текущей директории
    while((d=readdir(fd))!=NULL)//чтение записи, премещение указателя
    {
        printf("%lu -%s %d\n", d->d_ino,d->d_name, d->d_type);
    }//ид
    closedir(fd);
    return 0;
}
