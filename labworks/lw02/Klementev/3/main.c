#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

int main()
{
    printf("Лабораторная работа №2 Часть 3(1), выполнили Клементьев С.В., группа ИСТбд-21\n");
    int filedesc = 0;
    /* Открываем файл */
    filedesc = open("new.dat", O_CREAT|O_RDWR, 777);
    /* Увеличиваем длину файла с помощью вызова ftruncate(). */
    ftruncate(filedesc, 100*sizeof(int));
    int * ptr = (int *) mmap(NULL, 100*sizeof(int), PROT_WRITE, MAP_SHARED, filedesc, 0);
    /* Файловый дескриптор нам более не нужен, и мы его закрываем */
    close(filedesc);
    int * elptr = ptr;
    for (int i = 0; i < 100; i++)
    {
        (*elptr) = i;
        elptr++;
    }
    munmap((void*)ptr, 100*sizeof(int));

    return 0;
}
