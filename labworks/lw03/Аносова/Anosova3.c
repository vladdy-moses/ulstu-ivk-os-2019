
/*Лабораторная работа № 3.
Пункт № 3.
Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    printf ("Лабораторная работа № 3. Пункт № 3.Выполнила студентка гр. ИСТбд-22 Аносова Е.Р.");

    if (envp != NULL)
    for (int i=0; envp[i]; i++)
    {
        printf ("%s \n", envp[i]);
    }

    return 0;
}
