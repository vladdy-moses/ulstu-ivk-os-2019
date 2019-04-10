/*Лабораторная работа № 3.
Пункт № 1.
Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.*/


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
    printf ("Лабораторная работа № 3. Пункт № 1.\
            \n Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.");

    pid_t pid;
    pid_t ppid;

    pid = getpid();
    ppid = getppid();

    printf ("\n %d, %d", (int)pid, (int)ppid);
    return 0;
}


