#include<stdio.h>
#include<pthread.h>

void func(int *arg);

int main()
{
	pthread_t th1;
	int i = 100;
	void *v;
	printf("before pthread create\n");
	pthread_create(&th1,NULL,func,&i);
        printf("after pthread create and before pthread_join\n");
	pthread_join(th1,&v);
        printf("before pthread join\n");
	printf("in main:%d\n",(int *)v);
}

void func(int *arg)
{
	*arg=*arg+10;
	printf("in func:%d\n",*arg);
	pthread_exit(*arg);
}
