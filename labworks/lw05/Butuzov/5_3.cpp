//ИСТбд-22 Бутузов А.Е.>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>

/*Задание:Первая программа должна создавать сегмент разделяемой памяти и копировать туда
собственный исходный текст, вторая программа должна брать оттуда этот
текст, печатать его на экране и удалять сегмент разделяемой памяти из системы.*/
using namespace std;
int main()
{
    printf("Программа 1\n");
    int cpp = open("/home/andrey/Desktop/OS_GIT/Lab5/5_3.cpp", O_RDONLY);
    struct stat st;
    lstat("/home/andrey/Desktop/OS_GIT/Lab5/5_3.cpp", &st);
    int s = st.st_size;
    char pathname[] = "./output"; /* Имя файла, используемое для генерации ключа.
    Файл с таким именем должен существовать в текущей директории */
    key_t key; /* IPC ключ */
    /* Генерируем IPC ключ из имени файла output в текущей директории и номера
    экземпляра области разделяемой памяти 0 */
    if((key = ftok(pathname,0)) < 0){
    printf("Can\'t generate key\n");
    exit(-1);
    }
    int sh;
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)
        {
            printf("Error\n");
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)
            {
                printf("Error\n");
                return 1;
            }
            shmctl(sh, IPC_RMID, NULL);
            sh = shmget(key, s+sizeof(int), IPC_CREAT|0777);
        }
    }
    int* m = (int*)shmat(sh, NULL, 0);
    int* t = m;
    *t = s;
    t++;
    char * c = (char *)t;
    read(cpp, c, s);
    close(cpp);
    shmdt(m);
    return 0;
}
