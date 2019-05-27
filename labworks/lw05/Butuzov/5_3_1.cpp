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

    char pathname[] = "./output"; /* Имя файла, используемое для генерации ключа.
    Файл с таким именем должен существовать в текущей директории */
    key_t key; /* IPC ключ */
    /* Генерируем IPC ключ из имени файла output в текущей директории и номера
    экземпляра области разделяемой памяти 0 */
    if((key = ftok(pathname,0)) < 0){
    printf("Can\'t generate key\n");
    exit(-1);
    }
    int sh = shmget(key, sizeof(int), IPC_CREAT|0777);
    int* m = (int*)shmat(sh, NULL, 0);
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
    printf("%s", buff);
    shmdt(m);
    shmctl(sh, IPC_RMID, NULL);
    return 0;
}
