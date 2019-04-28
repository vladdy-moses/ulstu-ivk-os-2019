#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    printf("Мусина Наиля ИСТбд-21 \n");
    int fd=0;
    fd = open("1.txt", O_CREAT|O_RDWR, 777);
    char *a="1lab, Musina";
    write(fd,a,12);
    close(fd);
    return 0;
}
