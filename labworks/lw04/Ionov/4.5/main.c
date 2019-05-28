#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Лабораторная работа №4.5\n");
    printf("Выполнил студент группы ИСТбд-21 Ионов Р.Д\n");
	int fd;
	char str[]= "help";
    printf("Создаем FIFO \n");
    mknod("/home/labs/4labrab/4.4.1/fifo", //Имя файла (файла с таким именем быть не должно)
    S_IFIFO | 0666,//S_IFIFO  указывает, что системный вызов должен создать FIFO и 0666 устанавливает атрибуты прав доступа различных категорий пользователей (rw- rw- r--)
     0);// dev является несущественным в этой ситуации
    printf("FIFO открываем на запись\n");
	fd = open("/home/labs/4labrab/4.4.1/fifo", //Имя файла
	O_WRONLY);//только операция записи
	printf("Запись в FIFO\n");
	write(fd, str, strlen(str));//Если FIFO открывается только для записи, и флаг O_NDELAY не задан, то процесс, осуществивший системный вызов, блокируется до тех пор, пока какой-либо другой процесс не откроет FIFO на чтение.
	printf("Данные записаны\n");
	close(fd);// Закрываем входной поток данных
	return 0;
}
