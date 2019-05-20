#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
//Лабораторная работа №5.2
//Организация работы с разделяемой памятью
//Выполнила студентка гр.ИСТбд-22 Гуськова Ю.А.
int main()
{
    printf("Лабораторная работа №5.2\n");
    printf("Организация работы с разделяемой памятью\n");
    printf("Выполнила студентка гр.ИСТбд-22 Гуськова Ю.А.\n");
    printf("Задание: в разделяемой памяти размещается массив из трех целых чисел. Первый элемент\
            массива используется как счетчик для программы 1, второй элемент – для\
            программы 2, третий элемент – для обеих программ суммарно.\n");
    int *array; /* Указатель на разделяемую память */
    int shmid; /* IPC дескриптор для области разделяемой памяти */
    int nw = 1; /* Флаг необходимости инициализации элементов массива */
    char pathname[] = "/home/student/Documents/4/4_1/output";
    key_t key; /* IPC ключ */
    /* Генерируем IPC */
    if((key = ftok(pathname,0)) < 0)
    {
        printf("Can\'t generate key\n");
        exit(-1);
    }
    /* Создание разделяемой памяти */
    if((shmid = shmget(key, 3*sizeof(int),0666|IPC_CREAT|IPC_EXCL)) < 0)
    {
    /* Анализ ошибки создания*/
        if(errno != EEXIST)
        { /*прочие ошибки*/
        printf("Can\'t create shared memory\n");
        exit(-1);
        }
        else
        { /* Память уже существует */
            if((shmid = shmget(key, 3*sizeof(int), 0)) < 0)
            {
            printf("Can\'t find shared memory\n");
            exit(-1);
            }
        nw = 0;
        }
    }
    /*Отображение разделяемой памяти в адресное пространство текущего
    процесса. Обратите внимание на то, что для правильного сравнения мы яв-
    но преобразовываем значение -1 к указателю на целое.*/
    if((array = (int *)shmat(shmid, NULL, 0)) == (int *)(-1))
    {
    printf("Can't attach shared memory\n");
    exit(-1);
    }
    /* В зависимости от значения флага new либо инициализируем массив, ли-
    бо увеличиваем соответствующие счетчики */
    if(nw)
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
    /* Печатаем новые значения счетчиков, удаляем разделяемую память из
    адресного пространства текущего процесса и завершаем работу */
    printf("Program 1 was spawn %d times,program 2 - %d times, total - %d times\n",array[0], array[1], array[2]);
    if(shmdt(array) < 0)
    {
    printf("Can't detach shared memory\n");
    exit(-1);
    }
    return 0;
}
