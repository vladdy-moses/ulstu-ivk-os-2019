#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>


int main(){
    printf("Лабораторная работа №5.3 \nВыполнил Хуснутдинов А.И ИСТбд-21\n");
    int cpp = open("/home/asd/codeblocks/5laba/5.3/main.c", O_RDONLY);
    struct stat st;
    lstat("/home/asd/codeblocks/5laba/5.3/main.c", &st);//lstat получает информацию об атрибутах файла
    int s = st.st_size;
    key_t key = ftok("/home/asd/codeblocks/5laba/5.3/", 1);//генерируем ключ
    int sh;
    /* Создание разделяемой памяти */
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
    {
        if(errno != EEXIST)/*прочие ошибки*/
        {
            printf("Can\'t create shared memory\n");
            return 1;
        }
        else
        {
            if ((sh = shmget(key, 1, 0))<0)/* Память уже существует */
            {
                printf("Can\'t find shared memory\n");
                return 1;
            }
            shmctl(sh, IPC_RMID, NULL);//shmctl предназначен для получения информации об
                                       //области разделяемой памяти, изменения ее атрибутов и удаления из системы.
            sh = shmget(key, s+sizeof(int), IPC_CREAT|0777);
        }
    }
    //отображаем в адресное пространство
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
