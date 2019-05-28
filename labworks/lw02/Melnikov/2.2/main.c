#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
int main()
{
    printf("Лабораторная работа №2 Часть 2, выполнил Мельников Г.Р, группа ИСТбд-21\n");
    DIR * g1;
    /*Функция opendir позиционирует поток на первой записи директории*/
    g1 = opendir("/");///sergio из-за того что делал на его ноутбуке, мой категорически отказывается открывать Ubuntu
    /* Тип данных struct dirent представляет собой некоторую структуру данных, описывающую одну запись в директории. */
    struct dirent * d;
    int i = 200;
    while(g1 && i-- >0)
    {
        /* Чтение очередной записи из директории осуществляет функция readdir() */
        d = readdir(g1);
        if (d != NULL)
            printf("%s\n",d->d_name);
    }
    /* После окончания работы с директорией ее необходимо закрыть с помощью функции closedir() */
    closedir(g1);
    return 0;
}
