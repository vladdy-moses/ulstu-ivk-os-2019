#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
    printf("Бутузов А.Е. ИСТбд-22 №2.3\n");
    int fd;/* Файловый дескриптор */
    size_t length;/* Длина отображаемой части файла */
    int i;

    int * ptr;
    int * tmpptr;
    /* Создание файла 2_3.dat с 1000 структур*/
    /* Открываем файл */
    fd = open("2_3.dat", O_RDWR | O_CREAT,0666);
    /* Вычисляем будущую длину файла для записи в него 1000 структур */
    length = 1000*sizeof(int);
    /* Увеличиваем длину файла с помощью вызова ftruncate(). */
    ftruncate(fd, length);
    /* Файл отображаем с его начала (offset = 0) и до конца (length = длине файла). */
    ptr = (int *) mmap(NULL, length,PROT_WRITE, MAP_SHARED, fd, 0);
    /* Файловый дескриптор нам более не нужен, и мы его закрываем */
    close(fd);
    /* Если отобразить файл не удалось – сообщаем об ошибке */
    if (ptr == MAP_FAILED)
    {
        printf("Mapping failed!\n");
        exit(2);
    }
    /* В цикле заполняем образ файла числами */
    tmpptr = ptr;

    for( i = 1; i <= 1000; i++)
    {
        (*tmpptr) = i;
        tmpptr++;
    }
    /* Прекращаем отображать файл в память, записываем содержимое отображения на диск и освобождаем память. */
    munmap((void*)ptr, length);





    /*Отображение созданного файла 2_3.dat*/
    ptr = NULL;
    tmpptr = NULL;

    fd = open("2_3.dat", O_CREAT | O_RDONLY, 777);

    ftruncate(fd, length);

    ptr = (int *) mmap(NULL, length,PROT_READ, MAP_SHARED, fd, 0);
    close(fd);

    if (ptr == MAP_FAILED)
    {
        printf("Mapping failed!!!\n");
        exit(3);
    }

    tmpptr = ptr;

    for (i = 1; i <= 1000; i++)
    {
        printf("%i\n", *tmpptr);
        tmpptr++;
    }

    munmap((void*)ptr, length);

    return 0;
}
