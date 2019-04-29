/*Программа 2*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int *array; /*Указатель на разделяемую память*/
    int shmid; /*IPC дескриптор для области разделяемой памяти*/
    int new = 1; /*Флаг необходимости инициализации элементов массива*/
    char pathname[] = "1.c";
    key_t key; /*IPC ключ*/

    /*Генерируем IPC*/
    if ((key = ftok(pathname, 0)) < 0)
    {
        printf("Can't generate key \n");
        exit(-1);
    }

    /*Создание разделяемой памяти*/
    if((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0)
    {
        /*Анализ ошибки создания*/
        if (errno != EEXIST)
        {
            /*прочие ошибки*/
            printf("Can't create shared memory \n");
            exit(-1);
        }
        else
        {
            /*Память уже существует*/
            if ((shmid = shmget(key, 3*sizeof(int), 0)) < 0)
            {
                printf("Can't find shared memory \n");
                exit(-1);
            }
            new = 0;
        }
    }

    /*Отобржение разделяемой памяти в адресное пространство текущего
    процесса. Обратите внимание на то, что для правильного сравнения
    мы явно преобразовываем значение -1 к указателю на целое*/
    if ((array = (int*)shmat(shmid, NULL, 0)) == (int*)(-1))
    {
        printf("Can't attach shared memory \n");
        exit(-1);
    }

    /*В зависимости от значения флага либо инициализируем массив,
    либо увеличиваем соответствующие счетчики*/
    if (new)
    {
        array[0] = 0;
        array[1] = 1;
        array[2] = 1;
    }
    else
    {
        array[1] += 1;
        array[2] += 1;
    }

    /*Печатаем новые значения счетчиков, удаляем разделяемую память из
    адресного пространства текущего процесса и завершаем работу*/
    printf("Program 1 was spawn %d times, \
    program 2 - %d times, total - %d times \n",
    array[0], array[1], array[2]);

    if (shmdt(array) < 0)
    {
        printf("Can't detach shared memory \n");
        exit(-1);
    }
    return 0;
}
