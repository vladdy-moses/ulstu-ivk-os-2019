#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 1.1");
    int file=0;
    file=open("text.txt", O_CREAT|O_RDWR,0777);
    char *a="Hello world";
    write(file,a,11);
    close(file);
    return 0;
}
