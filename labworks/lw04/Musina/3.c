#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd[2];
    int pp = pipe(fd);//создаем pipe
    printf("Lab 4.3 Musina N.I. ISTbd-21  \n");
    if (pp == -1) //ошибка при создании pipe
    {
        printf("Error creating pipe\n");
    }
    int i = 0;
    while (write(fd[1], "0", sizeof(char)))
    {
        printf("%u ,byte\n", i);
        ++i;
    }
	return 0;
}
