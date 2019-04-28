#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char *argv[], char *envp[])
{
    char name[] = "/home/user/lab4/aaa/fif";
    char message[] = "Musina";
    printf("Lab 4.41 Musina N.I. ISTbd-21  \n");
    int fifo = mknod(name, S_IFIFO | 0666, 0);
	int fd = open(name, O_WRONLY);
	write(fd, message, strlen(message));
	close(fd);
    return 0;
}
