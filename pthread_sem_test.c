#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t sem;

void *func1()
{
	printf("in func1, sem_wait\n");
	sem_wait(&sem);
	printf("after sem_wait\n");
	printf("msg is hello manu\n");
        printf("exit from func1\n");
}

void *func2()
{
	printf("in func2,sem_post\n");
	sem_post(&sem);
	printf("after sem_post\n");
	printf("exit from func2\n");
}

int main()
{
	pthread_t th1,th2;
	pthread_create(&th1,NULL,func1,NULL);
	pthread_create(&th2,NULL,func2,NULL);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
}
