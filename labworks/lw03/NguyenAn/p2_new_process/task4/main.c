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
            printf("Child - PID = %d, Parent PID = %d\n", pid, ppid);
	    for (i = 0; i < 10; i++, a+=3)	    
	    	printf("Child - Result a (%d) = %d;\n", i, a);
	    printf("CHILD IS END UP!");
	    exit(0);
	    break;
	default:
	    printf("Parent - PID = %d, Parent PID = %d\n", pid, ppid);
	    for (i = 0; i < 5; i++, a += 2){ 
		printf("Parent - Result a (%d) = %d;\n", i, a);
	    	sleep(4000);
	    }
 	    break;
    }

    return 0;
}

