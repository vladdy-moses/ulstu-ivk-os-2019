#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/mman.h>

int main()
{
int fd;////файловый дескриптор
size_t length;
//длина отображаемой части
//ptr начюадрес выделенной облюпамяти
//tmpptr -ук-ль для перемещения внутри обл памяти
length=10*sizeof(int);
 printf("Мусина Наиля ИСТбд-21 lab 1.31\n");
 fd=open("/home/student/Documents/131/13.txt", O_RDONLY, 777);


   int *ptr=(int *)mmap(NULL,length, PROT_READ,MAP_SHARED,fd,0);
   close(fd);
   int *tmpptr=ptr;
   for(int i=0;i<=10;i++)
   {
        printf("%i ",*tmpptr);
        tmpptr++;
   }
   munmap((void*)ptr,length);
    return 0;
}
