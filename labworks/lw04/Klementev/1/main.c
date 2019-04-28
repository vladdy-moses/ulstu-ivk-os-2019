#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf ("Лабораторная работа №4 Часть 1, выполнили Клементьев С.В., группа ИСТбд-21\n");
    int fd[2];
    size_t size;
    char string[] = "Hi, my name is Sergio";
    char resstring[21];
    /* Создаем pipe */
    int er = pipe(fd);
    if (er != 0) {
        printf("Ошибка создания канала...\n");
    }
    else
    {
        // Запись всей строки вместе с признаком конца строки в канал
        printf("Начали запись строки...\n");
        /* Запись строки в поток */
        size = write(fd[1], string, 21);
        printf("Записали строку...\n");
        //* Чтение строки из канала
        printf("Начали чтение строки...\n");
        /* Чтение строки из канала */
        size = read(fd[0], resstring, 21);
        printf("Прочитали строку...\n");
        // Печать прочитанной строки
        printf("Прочитанная строка: \n");
        /* Печать прочитанной строки */
        printf("%s\n",resstring);
        /* Закрыть входной поток и завершить работу */
        close(fd[0]);
        close(fd[1]);
    }
    return 0;
}
