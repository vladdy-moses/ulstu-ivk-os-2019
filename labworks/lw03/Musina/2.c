#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    printf("Musina N. ИСТбд-21 лабораторная работа №3\n");
    pid=fork();
    if(pid>0)
        sleep(60);
    else
        exit(2);

    return 0;
}
