#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/*
	Лаб.раб. ОС №3.5
	Выполнил: Ахметов Э.Н. ИСТбд-22
*/
int main(int argc, char *argv[], char *envp[])
{
    pid_t pid;

	pid = fork();

	if (pid==0)
	{
        printf("child\n");
        execle("/usr/bin/printenv", "/usr/bin/printenv", 0, envp);
	}
	else
        printf("%s","parent");
    return 0;
}
