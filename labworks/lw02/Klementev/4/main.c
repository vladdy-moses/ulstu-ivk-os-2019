#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

int main()
{
    printf("Лабораторная работа №2 Часть 3(2), выполнили Клементьев С.В., группа ИСТбд-21\n");
    int filedesc = 0;
    /* Открываем файл */
    filedesc = open("new.dat", O_RDONLY, 0666);
    int * ptr = (int *) mmap(NULL, 100*sizeof(int), PROT_READ, MAP_SHARED, filedesc, 0);
    /* Файловый дескриптор нам более не нужен, и мы его закрываем */
    close(filedesc);
    int * elptr = ptr;
    for (int i = 0; i < 100; i++)
    {
        printf("%i ",*elptr);
        elptr++;
    }
    munmap((void*)ptr, 100*sizeof(int));

    return 0;
}
