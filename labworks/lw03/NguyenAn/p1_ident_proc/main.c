// Автор - an-nguen - ИСТбд-21
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define AUTHOR "Author - Нгуен Хыу Ан\n"

int main() {
    printf("%sPID = %d, Parent PID = %d\n", AUTHOR, getpid(), getppid());
    exit(0);
}

