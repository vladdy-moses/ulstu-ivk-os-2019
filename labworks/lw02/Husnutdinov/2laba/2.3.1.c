#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    printf("Лабораторная работа №2.3.1 \n Выполнил Хуснутдинов А.И ИСТбд-21\n");
    int fd = 0;
    fd = open("/home/asd/codeblocks/2.3laba/2.3.1laba/2.3.1laba/txt3.dat", O_RDONLY, 777);
    ftruncate(fd, 1000* sizeof(int));
    int*ptr = (int*) mmap(NULL,1000*sizeof(int), PROT_READ, MAP_SHARED,fd,0);
    close(fd);
    if(ptr == MAP_FAILED)
    {
        printf("MAP_FAILED");
        exit(2);
    }
    for (int i = 0; i<1000; i++)
    {
        printf("%i ", *(ptr+i));
    }
    munmap((void*)ptr, 1000*sizeof(int));
    return 0;
}
