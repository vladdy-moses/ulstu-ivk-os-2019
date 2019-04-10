/*Лабораторная работа № 3.
Пункт № 2.
Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("Лабораторная работа № 3. Пункт № 2.Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.");

    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        printf ("\n Ошибка. Новый процесс создать не удалось.");
    }
    else if (pid == 0)
    {
        printf ("\n Создан процесс-ребенок");
        printf ("%d", getpid());
        printf ("\n Процесс-ребенок находится в состоянии - закончил исполнение");
        exit(2);
    }
    else
    {
        printf ("\n Создан родительский процесс.");
        printf ("%d", getpid());
        scanf("%d",&pid);
    }

    return 0;
}

