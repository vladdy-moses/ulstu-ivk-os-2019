/*
Лабораторная работа№ 1.
Пункт № 5.
Выполнила студентка гр. ИСТбд-22
Аносова Екатерина Романовна.
*/
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
    printf ("Лабораторная работа № 1. \
    \n Пункт № 5. \
    \n Выполнила студентка гр. ИСТбд-22 \
    \n Аносова Екатерина Романовна.");

    DIR* directory;
    struct dirent *dir;

    directory=opendir("/");

    while ((dir=readdir(directory))!=NULL)
    {
        printf ("%d - %s [%d] \n", dir->d_ino, dir->d_name, dir->d_type);
    };

    closedir(directory);
    return 0;
}
