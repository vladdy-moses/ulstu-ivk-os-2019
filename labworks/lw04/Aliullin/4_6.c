///Лабараторная работа 4. Алиуллин Азат. ИСТбд-21
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main() {
	int fd;
	size_t size;
	char result[1024];
	printf("Открываем FIFO на чтение...\n");
	fd = open("/home/linux/2/3_4/fifo", O_RDONLY);
    //Если FIFO открывается только для чтения, и флаг O_NDELAY не задан,
    //то процесс, осуществивший системный вызов, блокируется до тех пор, пока
    //какой-либо другой процесс не откроет FIFO на запись.
    printf("Начало чтения...\n");
	char *s = result;// считываемый символ
	do {
		size = read(fd, s, 1);
		s++;
	} while (size != 0);//считоваем по одному символу пока они не закончатся
	printf("Данные прочитаны\n");
	printf("Результат: %s\n", result);
	close(fd);

	return 0;
}
