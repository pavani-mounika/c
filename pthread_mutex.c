#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

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
		pthread_mutex_lock(&mutex);
		if(i%2==0)
		{
			printf("even:%d\n",i);
		}
		else
			pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}

void *odd()
{
	int i;
	for(i=0;i<=10;i++)
	{
		pthread_mutex_lock(&mutex);
		if(i%2!=0)
		{
			pthread_cond_wait(&cond,&mutex);
			printf("odd:%d\n",i);
		}
		pthread_mutex_unlock(&mutex);
	}
}
