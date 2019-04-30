#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/mman.h>

int main()
{
    printf("Лабораторная работа 2.Выполнила студентка группы ИСТбд-21 Ахвандеева О.С.\ n");
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/");//открывает поток информации для директории

    if (!dir)
      {
        perror("diropen");//выводит ошибку
        exit(1);
      };

    while ( (entry = readdir(dir)) != NULL)
      {
        printf("%lu - %s [%d] %d\n",entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
      };

    closedir(dir);
}
