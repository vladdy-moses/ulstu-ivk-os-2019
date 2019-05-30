#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 2.3");

    pid_t pid;
    //При успешном создании нового процесса с этого места псевжопараллельно начинают работать старый и новый процесс
    pid=fork();

     if (pid>0)
     {
        printf("Zombie");
        sleep(5);

     }
     else
     {
        exit(2);
     }

    return 0;
}
