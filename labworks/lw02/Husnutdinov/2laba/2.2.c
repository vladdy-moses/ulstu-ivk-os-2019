#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
int main()
{
printf("Лабораторная работа №2.2 \n Выполнил Хуснутдинов А.И ИСТбд-21\n");
DIR * fd;
fd = opendir("/home/asd/codeblocks/2.2laba/2.2laba"); /// служит для открытия потока информации для директории, позиционирует поток на первой записи
struct dirent * d; ///структура данных, описывающая одну запись в директории
int i = 50;
    while(fd && i-->0)
    {
    d = readdir(fd);///осуществляет чтение очередной записи
    if (d != NULL)
    printf("%s\n",d->d_name);
    }
closedir(fd);
return 0;
}
