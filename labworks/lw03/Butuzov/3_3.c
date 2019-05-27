#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* Пример создания нового процесса с одинаковой работой процессов
ребенка и родителя */
int main()
{ pid_t pid, ppid;
printf("Бутузов А.Е. ИСТбд-22 №3.3\n");
int a = 0;
/* При успешном создании нового процесса с этого места псевдопараллельно
начинают работать два процесса: старый и новый */
(void)fork();
/* Узнаем идентификаторы текущего и родительского процесса (в каждом из
процессов !!!) */
pid = getpid();
ppid = getppid();
/*Общая схема организации различной работы процесса-ребенка и процес-
са-родителя выглядит так:*/
pid = fork();
if (pid == -1)
    printf("ERROR!\n");
else
    if (pid == 0)
        printf("I am child \n");
    else
        printf("I am parent \n");
for (int i = 0; i<5; i++){
	a++;
/* Печатаем значения PID, PPID и вычисленное значение переменной a (в
каждом из процессов !!!) */
printf("My pid = %d, my ppid = %d, result = %d\n", (int)pid, (int)ppid, a);
}

return 0;
}
