#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    printf ("Лабораторная работа №4 Часть 6, выполнили Клементьев С.В., группа ИСТбд-21\n");
	int fd;
	size_t size;
	char res[1024];
	printf("Открываем FIFO на чтение...\n");
	fd = open("/sergio/lab/fifo", O_RDONLY);
    /* Если FIFO открывается только для записи, и флаг O_NDELAY не задан, то процесс,
	осуществивший системный вызов, блокируется до тех пор, пока
    какой-либо другой процесс не откроет FIFO на запись. */
    printf("Начало чтения...\n");
    /* Считываем символ */
	char *symb = res;
	do {
		size = read(fd, symb, 1);
		symb++;

	} while (size != 0); // Cчитоваем по одному символу пока они не закончатся
	printf("Данные прочитаны\n");
	printf("Результат: %s\n", res);
	close(fd);
	return 0;
}
