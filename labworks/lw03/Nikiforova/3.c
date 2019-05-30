#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{


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
            //printf("Дочерний: \n");

            exit(0);//закончил исполнение

        }
        else
        {
            printf("Родительский: \n");
            sleep(5);//режим сна

        }
        printf("Nikiforova Alevtina\n");
            printf("ISTbd-21\n Lab 2.2");


    return 0;
}
