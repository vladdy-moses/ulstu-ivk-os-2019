#include <iostream>
#include <pthread.h>

int a = 0;

void *second (void *d)
{
a+=2;
int s_second = (int)pthread_self();
std::cout << "Вторая нить исполнения, " << s_second << " a = "<< a << std::endl;
return (void *) NULL;
}

void *third(void *d)
{
a+=4;
int s_third = (int) pthread_self();
std::cout << "Третий тред, такой же как второй, потому что почему нет, " << s_third << " a = "<<a<<std::endl;
return (void *) NULL;
}

int main()
{
std::cout << "Лабораторная работа №6 Лобина Михаила, ИСТбд-22" << std::endl;
pthread_t mythid, i_second, i_third; //в оригинале тут была ошибка О_о. Если её не нужно было править, извините <_<
pthread_create(&i_second, (pthread_attr_t *)NULL, second, NULL);
std::cout << "Создали тред, а не копипастнули пример " << i_second << std::endl;
pthread_create (&i_third, (pthread_attr_t *)NULL, third, NULL);
std::cout << "Третий тред, например, " << i_third << std::endl;
a++;
mythid = pthread_self(); //здесь не приводим, чтобы показать, что можно и не приводить
std:: cout << "Это главный тред с ИД = " << (int) mythid << " и a тут равно " << a << std::endl;
pthread_join(i_second, (void **) NULL);
pthread_join(i_third, (void **) NULL);
return 0;
}
