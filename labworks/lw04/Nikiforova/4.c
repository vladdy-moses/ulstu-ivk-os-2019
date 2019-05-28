#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 3.4\n");

    char name[]="/home/alya/Рабочий стол/labar/os3.4/fifo";
    char str[]="Hello";
    //заводится файл-метка
    int fifo=mknod(name,
                    S_IFIFO|0666,//указывает, что системный вызов должен создать ФИФО
                    0);

    int fd=open(name,O_WRONLY);
    write(fd,str,strlen(str));
    close(fd);
}
