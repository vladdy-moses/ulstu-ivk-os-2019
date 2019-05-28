#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 2.1");

    pid_t pid,ppid,pr;
    int a=0;
    //При успешном создании нового процесса с этого места псевжопараллельно начинают работать старый и новый процесс
    pr=fork();
    //Узнаем идентификаторы текущего и родительского процесса
    pid=getpid();//текущий
    ppid=getppid();//родительский для текущего
   // //pid=fork();
    if (pr==-1)
    {
        printf("Error\n");
    }
    else
        if(pr==0)
        {
            printf("Дочерний: \n");
        }
        else
        {
            printf("Родительский: \n");
        }
    //Перед выполнение след выражения а=0 в обоих процессах
    for (int i=0; i<3; i++)
    {   a++;
        //Печатаем значения и вычисленное значение а
        printf("My pid=%d, my ppid=%d, result=%d, pr=%d\n",(int)pid, (int)ppid,a,pr );

    }
    return 0;
}
