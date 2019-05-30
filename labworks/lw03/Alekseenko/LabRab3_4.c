#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[]){
printf("Лабораторная работа №3.4\n");
printf("Выполнил студент групппы ИСТбд-21 Алексеенко Д.В.\n");
execle("/bin/cat", "/bin/cat", "main.c", envp);
return 0;

}
