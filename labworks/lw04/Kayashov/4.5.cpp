#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
///Лабораторная работа №4.5
///Выполнил студент группы ИСТбд-22 Каяшов П.А.
int main()
{
    printf("Лабораторная работа №4.5\n");
    printf("Выполнил студент группы ИСТбд-22 Каяшов П.А./n");
	int fd;
	size_t size;
	char result[1024];
	printf("Открываем FIFO на чтение...\n");
	fd = open("/home/student/projects/fifo", O_RDONLY);
    ///Если FIFO открывается только для чтения, и флаг O_NDELAY не задан,
    ///то процесс, осуществивший системный вызов, блокируется до тех пор, пока
    ///какой-либо другой процесс не откроет FIFO на запись.
    printf("Начало чтения...\n");
	char *s = result;///считываемый символ
	do {
		size = read(fd, s, 1);
		s++;
	} while (size != 0);///считоваем по одному символу пока они не закончатся
	printf("Данные прочитаны\n");
	printf("Результат: %s\n", result);
	close(fd);

 	return 0;
}
