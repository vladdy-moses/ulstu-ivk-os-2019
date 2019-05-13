#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf ("Бутузов А.Е. ИСТбд-22 №3.1\n");
    pid_t pid, ppid; /*Тип данных pid_t является синонимом для одного из целочисленных типов языка C*/
    int a = 0;
    (void)fork();
    /* Узнаем идентификаторы текущего*/
    pid = getpid();
    ppid = getppid();/*и родительского процесса*/
    	a++;
    printf("pid = %d, ppid = %d", (int)pid, (int)ppid);/*родительский пероцесс всегда пердшествует текущему (на 1)*/
    return 0;
}
