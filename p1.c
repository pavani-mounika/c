#include<stdio.h>
#include<pthread.h>

void *thread1(void *arg);
void *thread(void *arg);

int res1,res2;

int main()
{	
	pthread_t pth1,pth2;
	
	int i=100;
	int j=200;

	pthread_create(&pth1,NULL,thread1,(void *)&i);
	pthread_create(&pth2,NULL,thread,(void *)&j);
	pthread_join(pth1,NULL);
	pthread_join(pth2,NULL);
}

void *thread1(void *arg)
{
	printf("i:%d\n",(int *)arg);
}

void *thread(void *arg)
{
	printf("j:%d\n",(int*)arg);
}
