#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
//Лабораторная работа №2.3
//Системные вызовы для работы с файлами, отображаемыми в память
//Выполнила студентка гр.ИСТбд-22 Гуськова Ю.А.
int main()
{
    /*struct A{
    double f;
    double f1;} *ptr, *tmpptr;*/
    printf("Лабораторная работа №2.3\n");
    printf("Системные вызовы для работы с файлами, отображаемыми в память\n");
    printf("Выполнила студентка гр.ИСТбд-22 Гуськова Ю.А.\n");
    int fd = 0;//файловый дескриптор
    fd = open("/home/student/Desktop/lab2_3/lb111.dat", O_RDONLY, 777);//открываем файл
    if (fd < 0)
    {printf("error");
    exit(2);
    }
    int * ptr;//ptr - начальный адрес выделенной области памяти
    ptr = (int *)mmap(NULL, 1000*sizeof(int), PROT_READ, MAP_SHARED, fd, 0);//отображаем файл с начала и до конца
    close(fd);                                        //PROT_READ - разрешено чтение области данных с файлом
    int *tmpptr = ptr;                                        //MAP_SHARED - все изменения в файле будут сохранены
    for(int i = 1; i<=1000; i++)
    {
    printf("%d ",*tmpptr);
    tmpptr++;
    }

    return 0;
}
