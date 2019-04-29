/* Переменные окружения */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
/*
	Лаб.раб. ОС №3.4
	Выполнил: Ахметов Э.Н. ИСТбд-22
*/
int main(int argc, char *argv[], char *envp[])
{
    execle("/usr/bin/printenv", "/usr/bin/printenv", 0, envp);
    return 0;
}
