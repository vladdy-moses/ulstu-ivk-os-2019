#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
printf("Айметова Р.А. ИСТ-21 лаб 3\n");
pid_t pid;
pid = fork();
if(pid>0){
sleep(1200);
}
else{
exit(2);
}
return 0;

}
