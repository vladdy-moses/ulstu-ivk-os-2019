#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int fdPC[2], fdCP[2], result;
	size_t size;
	char resC[17], resP[15];
	pipe(fdPC); //Канал для записи родителем, чтения потомком
	pipe(fdCP); //Канал для записи потомком, чтения родителем

    printf("Lab 4.2 Musina N.I. ISTbd-21  \n");
	result = fork();
	if (result > 0)
	{ //Родительский процесc
		size = write(fdPC[1], "Hello, child!", 17);//запись
		close(fdPC[1]);
		size = read(fdCP[0], resP, 15);//чтение родителем
		close(fdCP[0]);
		printf("Полученное родителем сообщение: %s\n", resP);
	}
	else
	{ //Дочерний процесс
		size = read(fdPC[0], resC, 17);//чтение
		close(fdPC[0]);
		printf("Полученное дочерним процессом сообщение: %s\n", resC);
		size = write(fdCP[1], "Hello, parent!", 15);//запись
		close(fdCP[1]);
	}
	return 0;
}
