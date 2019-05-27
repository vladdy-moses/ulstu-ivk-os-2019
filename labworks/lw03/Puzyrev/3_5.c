#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[])
  {
    printf("Управление процессами\n");
    printf("Выполнила студент группы ИСТбд-21 Пузырев И.И.\n");
    if (fork()==0)
        execle("/bin/cat", "/bin/cat", "main.c", envp);///Аргумент envp содержит переменные окружения,
            ///установленные в операционной системе для данного пользователя.
        ///Переменные окруженияможно взять те же, что пере-даются в функцию main()
    else printf("%s","Что-то пошло не так...");
    return 0;

  }
