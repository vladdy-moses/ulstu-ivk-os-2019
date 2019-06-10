#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int arcgc,char *argv[])
{
    printf ("Лабораторная работа № 2\
            \nЛарёхин Е.Н. Псбд-21 ");
    int fd;
    char buf[14];
    fd=open("txt1.txt",O_CREAT|O_WRONLY,0600);
    if (fd==-1)
    {
    printf ("Warning!");
    exit (1);
    }
    write(fd,"Hello world!\n",13);
    close (fd);
    fd=open("txt1.txt",O_RDONLY);
    if (fd==-1)
    {
    printf ("Warning1!");
    exit (1);
    }

    read (fd,buf,14);
    buf[13]='\0';
    close (fd);
    printf ("buf: %s\n",buf);

    return 0;
}
