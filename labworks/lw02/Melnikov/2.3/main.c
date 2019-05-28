#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

int main()
{
    printf("Лабораторная работа №2 Часть 3(1), выполнил Мельников Г.Р, группа ИСТбд-21\n");
    int g1 = 0;
    /* Открываем файл */
    g1 = open("gleb228.dat", O_CREAT|O_RDWR, 777);
    /* Увеличиваем длину файла с помощью вызова ftruncate(). */
    ftruncate(g1, 1000*sizeof(int));
    int * ptr = (int *) mmap(NULL, 1000*sizeof(int), PROT_WRITE, MAP_SHARED, g1, 0);
    /* Файловый дескриптор нам более не нужен, и мы его закрываем */
    close(g1);
    int * elptr = ptr;
    for (int i = 0; i < 1000; i++)
    {
        (*elptr) = i;
        elptr++;
    }
    munmap((void*)ptr, 1000*sizeof(int));

    return 0;
}
