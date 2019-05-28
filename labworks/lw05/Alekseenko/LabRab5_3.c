#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>
/// Лабораторная работа №5
/// Тема:Организация работы с разделяемой памятью.
/// Задание:Первая программа должна создавать сегмент разделяемой памяти и копировать туда
/// собственный исходный текст, вторая программа должна брать оттуда этот
/// текст, печатать его на экране и удалять сегмент разделяемой памяти из системы.
/// Выполнил студент группы ИСТбд-21 Алексеенко Д.В.

int main()
{
    printf("Выполнил студент группы ИСТбд-21 Алексеенко Д.В.\n");
    int cpp = open("/home/dmitry/Desktop/5/main1.cpp", O_RDONLY);
    struct stat st;
    lstat("/home/dmitry/Desktop/5/main1.cpp", &st);
    int size = st.st_size;
    key_t key = ftok("/home/dmitry/Documents/", 2);
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
    read(cpp, m, size);
    close(cpp);
    // удаляем разделяемую память из адресного
    // пространства текущего процесса и завершаем работу
    shmdt(m);
    return 0;
}
