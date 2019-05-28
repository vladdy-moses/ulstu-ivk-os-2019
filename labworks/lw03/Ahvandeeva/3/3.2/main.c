#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid, ppid;
    printf ("Лабораторная работа № 3.2.Выполнила студентка группы ИСТбд-21 Ахвандеева О.С.\n");
    int a = 0;
    pid=fork();
    ppid = getppid();//родительского
    pid = getpid();//дочернего
    //pid=fork();//новый процесс может быть порожден единственным способом – с помощью системного вызова fork()

    if (pid == 0)
        printf("\nДочерний элемент\n");
    else printf("\Продительский элемент\n");

    for (int i = 0; i<5; i++)
      {
        a++;
    // Печатаем значения PID, PPID и вычисленное значение переменной a (в каждом из процессов !!!)
    printf("My pid = %d, my ppid = %d, result = %d\n", (int)pid, (int)ppid, a);
      }

    return 0;
}
