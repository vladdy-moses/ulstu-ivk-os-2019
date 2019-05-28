#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])//Аргумент argv представляет собой массив из указателей на аргументы командной строки
{
printf ("Лабораторная работа №3 Часть 5, выполнили Мельников Г.Р, группа ИСТбд-21\n");
	/*если fork != 0, создание прошло неуспешно*/
	if (fork()!=0)
    {
		char** env;
        for (env = envp; *env != 0; env++)
        {
            char* thisEnv = *env;
            printf("%s\n", thisEnv);
        }
	}
	/*если fork == 0, создание прошло успешно*/
	else
        /* Системный вызов exec() изменяет пользовательский контекст текущего процесса, не создавая новый процесс*/
        (void)execle("/bin/cat", "/bin/cat", "main.c", (char*)0, envp);
return 0;
}
