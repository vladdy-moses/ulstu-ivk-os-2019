#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{

	if (fork()==0)
		execle("/bin/cat", "/bin/cat", "main.c", envp);
	else printf("%s","error");
    return 0;
}
