#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
/*Задание: модифицируйте программу, созданную при выполнении за-
дания, использующую вызов fork() с разным поведением процессов ребенка и
родителя", так, чтобы порожденный процесс запускал на исполнение новую
(любую) программу.*/
    printf ("Бутузов А.Е. ИСТбд-22 №3.5\n");
    pid_t pid;
	pid = fork();
	if (pid==0)
	{
        printf("Child process\n");
		execle("/usr/bin/printenv", "/usr/bin/printenv", 0, envp);
    }
	else printf("Parent process\n");
return 0;
}
