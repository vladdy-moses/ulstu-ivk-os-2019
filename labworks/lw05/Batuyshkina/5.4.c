/* Программа 2 */
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
    printf ("Лабораторная работа № 5.4\
            \nБатюшкиной А.Ю. ИСТбд-21\n");
    key_t key = ftok("output", 2);
    // Доступ к созданной области разделяемой памяти в дальнейшем обеспечивается ее дескриптором, который вернет системный вызов shmget()
    int sh = shmget(key, 5000, IPC_CREAT|0777);
    // Включить область разделяемой памяти в адресное пространство текущего процесса
    char* m = (char*)shmat(sh, NULL, 0);
    int length = *m;
    shmdt(m);
    sh = shmget(key, length+sizeof(int), IPC_CREAT|0777);
    m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    t++;
    char* c = (char *) t;
    char buff[length];
    for (int i = 0; i < length-1; i++)
    {
        buff[i] = *c;
        c++;
    }
    printf(buff);
    // Удаляем разделяемую память из адресного пространства текущего процесса и завершаем работу
    shmdt(m);
    // Удалить область разделяемой памяти из системы можно воспользоваться и системным вызовом shmctl()
    shmctl(sh, IPC_RMID, NULL);
    return 0;
}
