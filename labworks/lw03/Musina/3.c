#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{
    printf("Musina N. ИСТбд-21 лабораторная работа №3\n");
    execle("/bin/cat", "/bin/cat", "main.c", envp);
    return 0;
}

