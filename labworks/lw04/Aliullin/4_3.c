///Лабараторная работа 4. Алиуллин Азат. ИСТбд-21
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
	int fdParentToChild[2], fdChildToParent[2], result;
	size_t size;
	char resForChild[17], resForParent[15];
	pipe(fdParentToChild); //Канал для записи родителем, чтения потомком
	pipe(fdChildToParent); //Канал для записи потомком, чтения родителем
	result = fork();
	if (result > 0)
	{ //Родительский процесc
		close(fdParentToChild[0]);//Закрываем поток чтения родителем
		close(fdChildToParent[1]);//Закрываем поток записи потомком
		printf("Родитель: Начало записи строки...\n");
		size = write(fdParentToChild[1], "Hello, child!", 17);
		printf("Родитель: Конец записи строки\n");
		printf("Родитель: Ожидание получения строки...\n");
		size = read(fdChildToParent[0], resForParent, 15);
		printf("Родитель: Конец чтения полученной строки\n");
		printf("Родитель: Полученное сообщение: %s\n", resForParent);
		close(fdParentToChild[1]);//Закрываем поток записи родителя
		close(fdChildToParent[0]);//Закрываем поток чтения родителя
        printf("Родитель: Закрыл потоки.\n");
	}
	else
	{ //Дочерний процесс
	    close(fdParentToChild[1]);//Закрываем поток записи родителем
		close(fdChildToParent[0]);//Закрываем поток чтения родителем
		printf("Потомок: Начало чтения строки... \n");
		size = read(fdParentToChild[0], resForChild, 17);
		printf("Потомок: Конец чтения полученной строки \n");
		printf("Потомок: Полученное сообщение: %s\n", resForChild);
		printf("Потомок: Начало записи строки...\n");
		size = write(fdChildToParent[1], "Hello, parent!", 15);
		printf("Потомок: Конец записи строки\n");
		close(fdParentToChild[0]);//Закрываем поток чтения потомком
		close(fdChildToParent[1]);//Закрываем поток записи потомком
		printf("Потомок: Закрыл потоки. \n");
	}
	return 0;
}
