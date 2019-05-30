#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>

int main()
{
    printf("Лабораторная работа №5.3\n");
    printf("Выполнил студент группы ИСТбд-21 Ионов Р.Д\n");
    int c = open("main.c", O_RDONLY);
    struct stat st;
    lstat("main.c", &st);//lstat получает информацию об атрибутах файла
    int size = st.st_size;
    key_t key = ftok("output", 2);// Генерация ключа
    int sh;
    // Создание области разделяемой памяти
    if ((sh = shmget(key, 5000, IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)// Если ошибка возникла не из-за того, что сегмент разделяемой памяти уже существует прекращаем работу
        {
            printf("Can\'t create shared memory\n");
            exit(-1);
        }
        else
        {// Если из-за того, что разделяемая память уже существует, то пытаемся получить ее IPC дескриптор и, в случае удачи, сбрасываем флаг необходимости инициализации элементов массива
            if ((sh = shmget(key, 1, 0))<0)
             {
                printf("Can\'t find shared memory\n");
                exit(-1);
            }
            // Удаление область разделяемой памяти из системы
            shmctl(sh, IPC_RMID, NULL);//shmctl предназначен для получения информации об области разделяемой памяти, изменения ее атрибутов и удаления из системы.
            sh = shmget(key, 5000, IPC_CREAT|0777);
        }
    }
    char* m = (char*)shmat(sh, NULL, 0);// shmat() - включить область разделяемой памяти в адресное пространство текущего процесса
    // Читаем из c в область разделяемой памяти
    read(c, m, size);
    close(c);
    shmdt(m);// Удаляем разделяемую память из адресного пространства текущего процесса и завершаем работу
    return 0;
}
