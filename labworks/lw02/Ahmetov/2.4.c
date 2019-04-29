#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/*
	Лаб.раб. ОС №2.4
	Выполнил: Ахметов Э.Н. ИСТбд-22 
*/

int main()
{
	int f = 0;
	char *ntext = "new text!";

	f = open("file.txt", O_CREAT|O_WRONLY, 777);
	
	write(f,ntext, 21);
	close(f);

	return 0;
}
