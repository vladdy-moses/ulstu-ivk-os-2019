#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
/*Задание: напишите программу, создающую процесс-зомби. Выведите
на экран его pid и посмотрите в другом окне терминала, как обозначается
данный процесс при вызове команды просмотра состояния процессов (ко-
манда ps)*/
	printf("Лабораторная работа №3.5\n");
	printf("Управление процессами\n");
	printf("Выполнил студент группы ИСТбд-22 Каяшов П.А.\n");
	printf("Пример создания процесса-зомби\n");
	pid_t id, pid, ppid;
	id = fork();
	pid = getpid();
	ppid = getppid();
	if (id > 0)
	{
		printf("!!!!!!!!!!!!!!!!!!\n");
		sleep(10);
	}
	else
	{
		printf("PID - %d; PPID - %d\n", pid, ppid);
		exit(0);
	}
	printf("PID - %d; PPID - %d\n", pid, ppid);//1-run, 2-ready, 3-lock
	return 0;
}
