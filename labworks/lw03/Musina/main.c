/* Пример создания нового процесса с одинаковой работой процессов
ребенка и родителя */
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    pid_t pid, ppid,p;
    int a = 0;
/* При успешном создании нового процесса с этого места псевдопараллельно
начинают работать два процесса: старый и новый */
    printf("Musina N. ИСТбд-21 лабораторная работа №3\n");
/* Перед выполнением следующего выражения значение переменной a в
обоих процессах равно 0 */
   p=fork();
   //pid = getpid();
    ppid = getppid();
    pid = getpid();
   // p=fork();

    if(p==-1)
        {
            printf("error");
        }
    else
    if(p==0)
        {
            printf("child\n");
        }
    else
        {
            printf("parent\n");
        }

    for (int i = 0; i<5; i++)
    {
        a++;
/* Печатаем значения PID, PPID и вычисленное значение переменной a (в
каждом из процессов !!!) */
        printf("My pid = %d, my ppid = %d, result = %d\n", (int)pid, (int)ppid, a);
    }
    return 0;
}
