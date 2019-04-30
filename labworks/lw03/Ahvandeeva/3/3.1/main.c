#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid, ppid;
    printf ("Лабораторная работа № 3.1.Выполнила студентка группы ИСТбд-21 Ахвандеева О.С.\n");
    int a = 0;
    // С этого места псевдопараллельно начинают работать два процесса: старый и новый
    (void)fork();
    // Узнаем идентификаторы текущего и родительского процесса (в каждом из процессов !!!)
    ppid = getppid();
    pid = getpid();//дочернего
    //ppid = getppid();//родительского

    for (int i = 0; i<5; i++)
      {
        a++;
        // Печатаем значения PID, PPID и вычисленное значение переменной a (в каждом из процессов !!!)
        printf("My pid = %d, my ppid = %d, result = %d\n", (int)pid, (int)ppid, a);
      }

    return 0;
}
