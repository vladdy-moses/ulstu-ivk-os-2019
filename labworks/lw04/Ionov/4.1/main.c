#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    printf("Лабораторная работа №4.1\n");
    printf("Выполнил студент группы ИСТбд-21 Ионов Р.Д\n");
    int fd[2];
    size_t size;
    char string[] = "Hello, world!";//Строка для записи
    char resstring[14];//Строка для чтения
    int er = pipe(fd);//Создание канала
    if (er == 0) {//Проверка на успешность операции
    //Запись всей строки вместе с признаком конца строки в канал
        printf("\nЗапись всей строки вместе с признаком конца строки в канал\n");
        size = write(fd[1], string, 14);
    //Чтение строки из канала
        printf("Чтение строки из канала\n");
        size = read(fd[0], resstring, 14);
    //Печать прочитанной строки
        printf("Печать прочитанной строки \n");
        printf("%s\n",resstring);
    //Закрыть входной и выходной потоки
        close(fd[0]);
        close(fd[1]);
    } else {
        printf("\nОперация не выполнена\n");
    }
    return 0;
}
