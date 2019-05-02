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
    char input[140];
    printf("Lab 4.42 Musina N.I. ISTbd-21  \n");
	int fd = open(name, O_RDONLY);
	read(fd, input, 140);
	printf(">> %s\n", input);
	close(fd);
    return 0;
}
