///Лабораторная работа №2
///подготовила студентка гр. ИСТбд-22
///Тулисова А.А.

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Лабораторная работа №2. Часть 3.1.\
    \nПодготовила студентка гр.ИСТбд-22 Тулисова Анна.\n");
    int fd = 0;
    fd = open("mapped.dat", O_RDWR | O_CREAT, 0666);
    ftruncate(fd, 1000*sizeof(int));///увеличиваем длину файла

    int *ptr = (int *) mmap (NULL, 1000*sizeof(int), PROT_WRITE, MAP_SHARED,fd, 0);
    ///mmap() отображает файл в адресное пространство процесса из дискового
    ///от начала и до конца
    close(fd);

    if(ptr == MAP_FAILED)
    {
        printf("MAP_FAILED");
        exit(2);
    }

   // int *tmpptr = ptr;
    ///В цикле заполняем образ файла числами
    for (int i = 0; i < 1000; i++)
    {
        *(ptr+i) = i*i;
       // tmpptr++;
    }
    munmap((void *)ptr, 1000*sizeof(int));
    ///завершение отображения файла в адресном пространстве; записываем содержимое отображения на диск и освобождаем память
    return 0;
}
