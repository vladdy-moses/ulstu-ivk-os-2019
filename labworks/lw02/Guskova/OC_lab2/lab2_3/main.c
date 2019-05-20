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
    fd = open("lb111.dat", O_RDWR|O_CREAT, 0666);//открываем файл
    if (fd < 0)
    {printf("error");
    exit(2);
    }
    ftruncate(fd,1000*sizeof(int));
    int * ptr;//ptr - начальный адрес выделенной области памяти
    ptr = (int *)mmap(NULL, 1000*sizeof(int), PROT_WRITE, MAP_SHARED, fd, 0);//отображаем файл с начала и до конца
                                            //PROT_WRITE - разрешена запись области данных с файлом
                                             //MAP_SHARED - все изменения в файле будут сохранены
    close(fd);//закрываем файловый дескриптор
    if (ptr==MAP_FAILED)
    {printf("Mapping failed!\n");
    exit(2);}

    int * tmpptr = ptr;//tmpptr - указатель на перемещения внутри области памяти
    //в цикле записываем образ файла числами
    for (int i = 1; i <= 1000; i++)
    {
        *tmpptr=i;
        tmpptr++;
    }
    //прекращаем отображать файл в память, записываем содержимое отображения на иск и освобождаем память
    munmap((void*)ptr, 1000*sizeof(int*));
    return 0;
}
