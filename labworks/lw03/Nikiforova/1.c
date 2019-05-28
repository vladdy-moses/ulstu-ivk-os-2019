#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid,ppid;
    int a=0;
    //При успешном создании нового процесса с этого места псевжопараллельно начинают работать старый и новый процесс
    (void)fork();
    //Узнаем идентификаторы текущего и родительского процесса
    pid=getpid();
    ppid=getppid();
    //Перед выполнение след выражения а=0 в обоих процессах
    a++;
    //Печатаем значения и вычисленное значение а
    printf("My pid=%d, my ppid=%d, result=%d\n",(int)pid, (int)ppid,a );
    return 0;
}
