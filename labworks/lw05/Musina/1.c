#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nw = 1;
	int *array; /* Указатель на разделяемую память */
	int shmid; /* IPC дескриптор для области разделяемой памяти */
	char pathname[] = "./output"; /* Имя файла, используемое для генерации ключа. */
	key_t key; /* IPC ключ */
	printf("lab 5.1 Musina\n");
	/* Генерируем IPC ключ из имени файла 1.c*/
	if((key = ftok(pathname,0)) < 0)
	{
		printf("Can\'t generate key\n");
		exit(-1);
	}
	/* Эксклюзивно создаем разделяемую память для ключа */
	if ((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0)
	{
		/* смотрим, из-за чего возникла ошибка */
		if(errno != EEXIST)
		{
			/* Если по неизвестной причине – прекращаем работу */
			printf("Can\'t create shared memory\n");
			exit(-1);
		}
		else
		{
			/* Если разделяемая память существует — пытаемся получить ее IPC */
			if((shmid = shmget(key, 3*sizeof(int), 0)) < 0)
			{
				printf("Can\'t find shared memory\n");
				exit(-1);
			}
			nw=0;
		}
	}
	/* Отображаем разделяемую память в адресное пространство текущего процесса.*/
	if((array = (int*) shmat(shmid, NULL, 0)) == (int*)(-1))
	{
		printf("Can't attach shared memory\n");
	}

    if(nw)
    {
        array[0] = 1;
        array[1] = 0;
        array[2] = 1;
    }
    else
    {
        array[0] += 1;
        array[2] += 1;
    }
    /* Печатаем новые значения счетчиков, удаляем разделяемую память из ад-
    ресного пространства текущего процесса и завершаем работу */
    printf("Program 1 was spawn %d times,program 2 - %d times, total - %d times\n",array[0], array[1], array[2]);
	/* Удаляем разделяемую память из адресного пространства текущего процесса и завершаем работу */
	if (shmdt(array) < 0)
	{
		printf("Can't detach shared memory\n");
		exit(-1);
	}
	return 0;
}
