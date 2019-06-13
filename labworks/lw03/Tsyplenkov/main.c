#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[], char *envp[])
{
    printf("Лабораторная работа №3 Задание 3\n\
Выполнил студент ИСТбд-21 Цыпленков Д. А.\n");
    pid_t pid, ppid;
int i, a = 0, result=-1;
/* При успешном создании нового процесса с этого места
псевдопараллельно начинают работать два процесса: старый и новый */
result = fork();
/* Узнаем идентификаторы текущего и родительского
процесса (в каждом из процессов !!!) */
pid = getpid();ppid = getppid();
/* Перед выполнением следующего выражения значение переменной a
в обоих процессах равно 0 */
a++;
/* Печатаем значения PID, PPID
и вычисленное значение переменной a(в каждом из процессов !!!) */
if (result==-1)
    {
	    printf("Error!");
	    exit(1);
    }
if (result == 0)
    {
	    execle("/bin/cat", "/bin/cat", "main.c", 0, envp);
    }
	else
	{
	    printf("PARENT - DO NOTHING\n");
    }
    return 0;
}
