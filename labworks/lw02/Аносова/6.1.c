
/*
Лабораторная работа№ 1.
Пункт № 6.
Выполнила студентка гр. ИСТбд-22
Аносова Екатерина Романовна.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main()
{
    printf ("Лабораторная работа № 1. \
    \n Пункт № 6. \
    \n Выполнила студентка гр. ИСТбд-22 \
    \n Аносова Екатерина Романовна.");

    int fdir;
    size_t len;

    fdir=open("mapped.dat", O_RDWR|O_CREAT, 777);
    len=1000*sizeof(int);
    ftruncate(fdir, len);
    int *ptr=(int*)mmap(NULL, len, PROT_WRITE, MAP_SHARED, fdir, 0);
    close(fdir);

    if (ptr==MAP_FAILED)
    {
        printf("Mapping failed!\n");
        exit(2);
    }
    int* tmpptr = ptr;
    for (int i=0; i<1000; i++)
    {
        *tmpptr=i;
        *tmpptr++;
    }
    munmap((void*)ptr, len);

    return 0;
}
