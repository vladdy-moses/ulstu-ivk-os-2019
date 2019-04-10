/*Лабораторная работа № 3.
Пункт № 2.
Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
    printf ("Лабораторная работа № 3.\
            \n Пункт № 2.\
            \n Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.");
    pid_t pid, ppid;
    int a = 0;

    (void)fork();

    pid = getpid();
    ppid = getppid();

    for (int i=0; i<5; i++)
    {
        a++;
        printf ("\n My pid = %d, my ppid = %d, result = %d\n", (int)pid, (int)ppid, a);
    }
    return 0;
}
