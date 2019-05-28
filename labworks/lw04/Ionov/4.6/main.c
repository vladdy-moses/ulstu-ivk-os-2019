#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf("Лабораторная работа №4.6\n");
    printf("Выполнил студент группы ИСТбд-21 Ионов Р.Д\n");
	int fd;
	size_t size;
	char result[1024];
	printf("Открываем FIFO на чтение\n");//Если FIFO открывается только для чтения, и флаг O_NDELAY не задан,
    //то процесс, осуществивший системный вызов, блокируется до тех пор, пока какой-либо другой процесс не откроет FIFO на запись.
	fd = open("/home/labs/4labrab/4.4.1/fifo", //Имя файла
	O_RDONLY);// только операция чтения
    printf("Чтение данных из FIFO\n");
	char *s = result;// считываемый символ
	do {
		size = read(fd, s, 1);
		s++;
	} while (size != 0);//считоваем по одному символу пока они не закончатся
	printf("Печать данных: %s\n", result);
	close(fd);
	return 0;
}
