#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

/*
	Лаб.раб. ОС №2.6
	Выполнил: Ахметов Э.Н. ИСТбд-22 
*/

int main()
{
    int fd;
    size_t length;
    int i;

    int *ptr;
    int *tmpptr;

    fd = open("1.dat", O_RDWR | O_CREAT, 0666);

    length = 1000 * sizeof(int);

    ftruncate(fd, length);

    ptr = (int *) mmap(NULL, length,
        PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    if(ptr == MAP_FAILED)
    {
        printf("Mapping failed!\n");
        exit(2);
    }

    tmpptr = ptr;

    for( i = 1; i <= 1000; i++)
    {
        (*tmpptr) = i;
        tmpptr++;
    }

    munmap((void*) ptr, length);

    ptr = NULL;
    tmpptr = NULL;

    fd = open("1.dat", O_CREAT | O_RDONLY, 777);
     ftruncate(fd, length);

     ptr = (int*) mmap(NULL, length,
        PROT_READ, MAP_SHARED, fd, 0);
    close(fd);

    if(ptr == MAP_FAILED)
    {
        printf("Mapping 2 failed!\n");
        exit(3);
    }

    tmpptr = ptr;

    for(i = 1; i <= 1000; i++)
    {
        printf("%i\n", *tmpptr);
        tmpptr++;
    }

    munmap((void*)ptr, length);

    return 0;
}
