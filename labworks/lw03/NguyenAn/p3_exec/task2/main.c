#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
    int success = fork();

    switch(success) {
	case -1:
	    printf("ERROR!");
	    exit(-1);
	    break;
	case 0:
	    execv("/bin/printenv", argv);
	    break;
	default:
	    printf("PARENT - DO NOTHING\n");
	    //execv("/bin/printenv", argv);
	    break;
    }
    return 0;
}
