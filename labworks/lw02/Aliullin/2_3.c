#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
    printf("лабораторная работа 2. Алиуллин. ИСТбд-21\n");
    int file = 0;
    file = open("txt4.txt", O_CREAT|O_RDWR);

    ftruncate(file, 1000*sizeof(int));///увеличение длины файла для 1000 интовых значений
    int * ptr = (int *) mmap(NULL, 1000*sizeof(int), PROT_WRITE, MAP_SHARED, file, 0);///файл отображаем от начала и до конца
    if (ptr == MAP_FAILED) {
        printf("произошла ошибка\n");
        exit(1);
    }
    close(file);
    int * tmpptr = ptr;
    ///заполняем образ файла числами
    for (int i = 0; i < 1000; i++) {
        (*tmpptr) = i;
        tmpptr++;
    }
    ///прекращаем отображение файла в память, отображаем на диск и освобождаем память
    munmap((void*)ptr, 1000*sizeof(int));

    return 0;
    }
