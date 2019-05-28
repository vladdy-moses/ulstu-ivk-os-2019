#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    printf("Nikiforova Alevtina\n");
    printf("ISTbd-21\n Lab 3.3\n");

    int fd[2];

    int pr=pipe(fd);
    if (pr==-1)
    {
        printf("Error");
    }
    int i=0;
    while (write(fd[1], "0", sizeof(char)))
    {
        printf("%u\n",i);
        i++;
    }

    return 0;
}


