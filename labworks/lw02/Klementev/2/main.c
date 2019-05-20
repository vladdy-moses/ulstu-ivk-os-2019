#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
int main()
{
    printf("Лабораторная работа №2 Часть 2, выполнили Клементьев С.В., группа ИСТбд-21\n");
    DIR * fd;
    /*Функция opendir позиционирует поток на первой записи директории*/
    fd = opendir("/sergio/lab");
    /* Тип данных struct dirent представляет собой некоторую структуру данных, описывающую одну запись в директории. */
    struct dirent * d;
    int i = 50;
    while(fd && i-- >0)
    {
        /* Чтение очередной записи из директории осуществляет функция readdir() */
        d = readdir(fd);
        if (d != NULL)
            printf("%s\n",d->d_name);
    }
    /* После окончания работы с директорией ее необходимо закрыть с помощью функции closedir() */
    closedir(fd);
    return 0;
}
