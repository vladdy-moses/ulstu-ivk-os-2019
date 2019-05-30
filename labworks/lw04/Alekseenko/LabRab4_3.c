#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
///Лабораторная работа №4.3
///Тема:Потоковое межпроцессное взаимодействие.Межпроцессное взаимодействие через канал pipe.
///Задание: напишите программу для определения размера канала в используемой операционной системе.
///Учтите, что при попытке записи в канал,в котором нет места, системный вызов write завершится с ошибкой.
///Выполнил студент группы ИСТбд-21 Алексеенко Д.В.


int main()
{
    printf("Выполнил студент группы ИСТбд-21 Алексеенко Д.В.\n");
	int fd[2], result;
	size_t size;
	pipe(fd);
	result = fork();
	if (result > 0)
	{//Родительский процесc
		int buf = 0;
		close(fd[0]);//Закрываем поток чтения
		while (1)
		{ // Родитель в бесконечном цикле записывает по 1 байту в поток
			buf++;
			size = write(fd[1],"", 1);
			printf("%d байт \n ", buf); //размер канала в используемой операционной системе
		}

		close(fd[1]);//Закрываем поток записи
	}
	else
	{//Дочерний процесс
		close(fd[1]);//Закрываем поток записи
		while (1); // Потомок ничего не читает из потока
		close(fd[0]);//Закрываем поток чтения
	}
	return 0;
}
