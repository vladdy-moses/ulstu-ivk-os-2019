#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t pid, ppid;
    ppid = getppid();
    pid = getpid();
    printf("Musina N. ИСТбд-21 лабораторная работа №3\n");
    printf("My pid = %d, my ppid = %d\n", (int)pid, (int)ppid);
    return 0;
}
