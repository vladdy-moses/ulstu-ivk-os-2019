#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
    printf("Лабораторная работа №2.1\n");
    printf("Выполнил студент группы ИСТбд-21 Ионов Р.Д\n");
    int f=0;
    f=open("txt2_1", O_RDWR | O_CREAT, 0664);//rdwr - ждя ввода/ввывода, creat - создание файла, 777 - права доступа
    char txt1[] = "первый файл";//заносим запись в переменную
    write (f, txt1, 21);//заносим переменную в файл и опр колво знаков(кириллица кодируется в 2 байта, другие символы в 1
    close (f);

    return 0;
}
