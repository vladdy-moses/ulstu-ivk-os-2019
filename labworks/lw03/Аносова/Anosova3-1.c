/*Лабораторная работа № 3.
Пункт № 3.
Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    printf ("Лабораторная работа № 3. Пункт № 3. Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.");

    pid_t pid;

    pid = fork();

    if (pid == -1)
    {
        printf ("\n Ошибка. Новый процесс создать не удалось.");
    }
    else if (pid == 0)
    {
        printf ("\n Создан процесс-ребенок");
        (void)execl ("/bin/cat", "/home/student/tmp", "Anosova1.c", (char*)0);
    }
    else
    {
        printf ("\n Создан родительский процесс.");
    }

    return 0;
}
