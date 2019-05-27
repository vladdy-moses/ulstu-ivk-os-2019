/* Пример создания нового процесса с одинаковой работой процессов
ребенка и родителя */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
///Алиуллин Азат. ИСТбд-21. Лабараторная работа 3.
int main(int argc, char *argv[], char *envp[])
{
	int test = fork();
	if (test == 0)
		execle("/home/linux/2_1/bin/Debug/2_1", "/home/linux/2_1/bin/Debug/2_1", 0, envp);
	else printf("%s","FOR RUSS AND THE ALLFATHER");
    return 0;
}
