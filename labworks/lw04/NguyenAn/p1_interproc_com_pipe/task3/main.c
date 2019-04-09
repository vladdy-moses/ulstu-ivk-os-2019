#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define AUTHOR "Нгуен Х.А."
#define GROUP "ИСТбд-21"

void print_author_and_group() {
    printf("Лабораторная работа №4\n Автор - %s\n группа - %s \n\n", AUTHOR, GROUP);
}

int main() {
    print_author_and_group();

    int fd[2], res_pipe, size, symbols_count = 0;

    /* Создаём канал */
    res_pipe = pipe(fd);

    /* Проверка создания канала */
    if (res_pipe == -1) 
	exit(1);

    while(1) {
	// write - возвращает кол-во записанных символов
	// При ошибке возвращает -1
	size = write(fd[1], "", 1);
	symbols_count++;
	printf("Кол-во записанных символов = %ld, Кол-во символов = %ld \n", size, symbols_count);
    }

    close(fd[0]);
    close(fd[1]);

    return 0;
}
