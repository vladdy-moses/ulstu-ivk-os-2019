/* Пример создания нового процесса с одинаковой работой процессов
ребенка и родителя */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{
    printf ("Лабораторная работа №3.5 Ильинский М.В. ИСТбд-22\n");
    pid_t pid;
	pid = fork();
	if (pid==0)
		execle("/bin/cat", "/bin/cat","/home/student/Documents/3.5lab/main.c", 0, envp);
	else printf("Father");
return 0;
}
