#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf ("Лабораторная работа №4 Часть 1, выполнил Мельников Г.Р., группа ИСТбд-21\n");//
    int g1[2];
    size_t size;
    char string[] = "Hello, how are you,man?";
    char newstring[23];
    /* Создаем pipe */
    int er = pipe(g1);// именованный канал область памяти не досупная польз процессам напрямую
    if (er != 0) {
        printf("Ошибка\n");
    }
    else
    {
        // Запись всей строки вместе с признаком конца строки в канал
        printf("запись началась\n");
        /* Запись строки в поток */
        size = write(g1[1], string, 23);
        printf("запись закончена\n");
        //* Чтение строки из канала
        printf("чтение началось\n");
        /* Чтение строки из канала */
        size = read(g1[0], newstring, 23);
        printf("чтение завершено\n");
        // Печать прочитанной строки
        printf("строка: \n");
        /* Печать прочитанной строки */
        printf("%s\n",newstring);
        /* Закрыть входной поток и завершить работу */
        close(g1[0]);
        close(g1[1]);
    }
    return 0;
}
