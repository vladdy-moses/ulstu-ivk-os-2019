#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("Лабораторная работа №3.3 \nВыполнил Хуснутдинов А.И ИСТбд-21\n");
    int x;
    pid_t pid;
    pid = fork();
    printf("%d", pid);
    if (pid>0)
        scanf(x);
    else
        exit(2);
    return 0;
}
