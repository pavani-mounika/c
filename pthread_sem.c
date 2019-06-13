#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t sem; 

void *even();
void *odd();

int main()
{
	pthread_t th1,th2;
	pthread_create(&th1,NULL,even,NULL);
	pthread_create(&th2,NULL,odd,NULL);

	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
}

void *even()
{
	int i;
	for(i=0;i<=10;i++)
	{
		if(i%2==0)
			printf("even:%d\n",i);
		else
			sem_post(&sem);
	}
}

void *odd()
{
	int i;
	for(i=0;i<=10;i++)
	{
		if(i%2==1)
		{	
			sem_wait(&sem);
			printf("%d\n",i);
		}
	}
}
