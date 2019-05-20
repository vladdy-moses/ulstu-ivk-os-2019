#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
{printf("Айметова Р.А. ИСТ-21 лаб 3\n");
// fork();
if (fork()==0)
execle("/bin/cat", "/bin/cat", "main.c", envp);//Аргумент envp содержит переменные окружения, установленные в операционной системе для данного пользователя.
//Переменные окруженияможно взять те же, что пере-даются в функцию main()
else printf("%s","Что-то пошло не так...");
return 0;
}
