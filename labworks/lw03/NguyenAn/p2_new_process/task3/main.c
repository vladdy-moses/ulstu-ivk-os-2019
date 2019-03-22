// Автор - an-nguen - ИСТбд-21
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define AUTHOR "Author - Нгуен Хыу Ан\n"

int main() {
    printf(AUTHOR);	
    int success = -1, pid, ppid, i, a = 0;

    success = fork();

    pid = getpid();
    ppid = getppid();

    switch(success) {
	case -1:
	    printf("Error!");
	    exit(1);
	    break;
        case 0:
	    for (i = 0; i < 10; i++, a+=3)	    
	    	printf("Child - Result a (%d) = %d;\n", i, a);
	    break;
	default:
	    for (i = 0; i < 3; i++, a += 2) 
		printf("Parent - Result a (%d) = %d;\n", i, a);
 	    break;
    }
    printf("PID = %d, Parent PID = %d, result = %d\n", pid, ppid, a);
    exit(0);
}

