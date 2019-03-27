// Автор - an-nguen - ИСТбд-21
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define AUTHOR "Author - Нгуен Хыу Ан\n"

int main() {
    printf(AUTHOR);	
    int pid, ppid, i, a = 0;

    fork();

    pid = getpid();
    ppid = getppid();

    for (i = 0; i < 100; i++, a++) 
        printf("a = %d\n", a);

    printf("PID = %d, Parent PID = %d, result = %d\n", pid, ppid, a);
    exit(0);
}

