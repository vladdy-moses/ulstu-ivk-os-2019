#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/stat.h>


int main(){
    printf("���.���.5.3.��������� ��������� ������ �����-21 ���������� �.�.");
    int cpp = open("/home/student/new/5/main.c", O_RDONLY);
    struct stat st;
    lstat("/home/student/new/5/main.c", &st);//lstat �������� ���������� �� ��������� �����
    int s = st.st_size;
    key_t key = ftok("/home/student/new/5", 1);//���������� ����
    int sh;
    /* �������� ����������� ������ */
    if ((sh = shmget(key, s+sizeof(int), IPC_CREAT|IPC_EXCL|0777))<0)
     {
        if(errno != EEXIST)/*������ ������*/
          {
            printf("Can\'t create shared memory\n");
            return 1;
          }
        else
          {
            if ((sh = shmget(key, 1, 0))<0)/* ������ ��� ���������� */
              {
                printf("Can\'t find shared memory\n");
                return 1;
              }
            shmctl(sh, IPC_RMID, NULL);//shmctl ������������ ��� ��������� ���������� ��
                                       //������� ����������� ������, ��������� �� ��������� � �������� �� �������.
            sh = shmget(key, s+sizeof(int), IPC_CREAT|0777);
          }
    }

    //���������� � �������� ������������
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
