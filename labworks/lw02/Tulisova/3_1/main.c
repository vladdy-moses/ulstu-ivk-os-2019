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
    printf("Лабораторная работа №2. Часть 3.2.\
    \nПодготовила студентка гр.ИСТбд-22 Тулисова Анна.\n");
    int fd = 0;
    fd = open("/home/student/Рабочий стол/Tulisova/3/mapped.dat", O_RDONLY,777);
    ftruncate(fd, 1000*sizeof(int));

    int *ptr = (int *) mmap (NULL, 1000*sizeof(int), PROT_READ, MAP_SHARED, fd, 0);
    close(fd);

    if(ptr == MAP_FAILED)
    {
        printf("MAP_FAILED");
        exit(2);
    }

   // int *tmpptr = ptr;
    for (int i = 0; i < 1000; i++)
    {
        printf("%i ",*(ptr+i));
        //tmpptr++;
    }
    munmap((void *)ptr, 1000*sizeof(int));
    return 0;
}
