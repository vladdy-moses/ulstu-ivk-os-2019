///Лабораторная работа №2
///подготовила студентка гр. ИСТбд-22
///Тулисова А.А.
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
int main()
{
    printf("Лабораторная работа №2. Часть 2. \n Подготовила студентка гр.ИСТбд-22 Тулисова Анна.\n");
    DIR * fd;
    fd = opendir("/home/student/Рабочий стол/Tulisova"); /// служит для открытия потока информации для директории,  позиционирует поток на первой записи
    struct dirent * d; ///структура данных, описывающая одну запись в директории
    int i = 50;
    while(fd && i-- >0)
    {
        d = readdir(fd);///осуществляет чтение очередной записи
        if (d != NULL)
            printf("%s\n",d->d_name);
    }
    closedir(fd);
    return 0;
}
