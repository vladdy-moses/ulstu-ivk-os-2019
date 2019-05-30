#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    printf("Лабораторная работа №5 Задание 2.1\n\
Выполнил студент ИСТбд-21 Цыпленков Д. А.\n");
    int c = open("1.c", O_RDONLY);
    struct stat st;
    lstat("1.c", &st);
    int size = st.st_size;
    key_t key = ftok("/", 2);
    int sh;
    // Создание области разделяемой памяти
    if ((sh = shmget(key, 5000, IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)
        {
            printf("Ошибка!");
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                printf("Ошибка!");
                return 1;
            }
            // удаление область разделяемой памяти из системы
            shmctl(sh, IPC_RMID, NULL);
            sh = shmget(key, 5000, IPC_CREAT|0777);
        }
    }

    // shmat() - включить область разделяемой памяти в адресное
    // пространство текущего процесса.
    char* m = (char*)shmat(sh, NULL, 0);
    // Читаем из cpp в область разделяемой памяти
    read(c, m, size);
    close(c);
    // удаляем разделяемую память из адресного
    // пространства текущего процесса и завершаем работу
    shmdt(m);
    return 0;
}
