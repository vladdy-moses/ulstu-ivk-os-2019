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
int fd;//////файловый дескриптор
size_t length;
//длина отображаемой части
//ptr начюадрес выделенной облюпамяти
//tmpptr -ук-ль для перемещения внутри обл памяти
 printf("Мусина Наиля ИСТбд-21 lab 1.3\n");
 fd=open("13.txt", O_CREAT|O_RDWR, 777);
   length=10*sizeof(int);
   ftruncate(fd,length);
   int *ptr=mmap(NULL,length, PROT_WRITE,MAP_SHARED,fd,0);
   close(fd);
   if(ptr==MAP_FAILED)//если не удалось отобразить
   {
        printf("Mapping failed\n");
        exit(2);
   }
   int *tmpptr=ptr;
   for(int i=0;i<=10;i++)//заполняем образ файла числами
   {
        (*tmpptr)=i;
        tmpptr++;
   }//прекращаем отображать в память, записываем содержимое на диск
   munmap((void*)ptr,length);//освобождаем память
    return 0;
}
