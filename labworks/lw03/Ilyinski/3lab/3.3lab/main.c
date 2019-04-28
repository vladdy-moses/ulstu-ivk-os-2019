#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pid_t pid, ppid;
    int a = 0;
    /* При успешном создании нового процесса с этого места псевдопараллельно
    начинают работать два процесса: старый и новый */
    /* Узнаем идентификаторы текущего и родительского процесса (в каждом из
    процессов !!!) */
    pid = getpid();
    ppid = getppid();
    pid = fork();
    /* Перед выполнением следующего выражения значение переменной a в
    обоих процессах равно 0 */
    if (pid == 0)
    {
        printf("Child!\n");
        exit(0);
    }
    else
        printf("Father!");
    for (int i = 0; i<10; i++)
    {
        a++;
    /* Печатаем значения PID, PPID и вычисленное значение переменной a (в
    каждом из процессов !!!) */
        printf("My pid = %d, my ppid = %d, result = %d\n", (int)pid, (int)ppid, a);
    }
    return 0;
}
