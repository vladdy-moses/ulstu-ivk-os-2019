#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[], char *envp[]){
printf("Управление процессами\n");
printf("Выполнила студент группы ИСТбд-21 Пузырев И.И.\n");
execle("/bin/cat", "/bin/cat", "main.c", envp);
return 0;

}
