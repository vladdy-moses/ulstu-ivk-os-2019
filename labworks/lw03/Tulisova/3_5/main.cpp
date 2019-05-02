#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{
pid_t new_proc;
	printf("Лабораторная работа №3. Часть 5. \n Подготовила студентка гр.ИСТбд-22 Тулисова Анна.\n");
	new_proc = fork();
	if (new_proc == -1)
		printf("Ошибка процесса!\n");
	else
	{
		if (new_proc == 0)
			execle("/home/student/new/2_1/bin/Debug/2_1", "/home/student/new/2_1/bin/Debug/2_1", 0, envp);
		else printf("%s", "Запущен родительский процесс!");
	}
return 0;
}
