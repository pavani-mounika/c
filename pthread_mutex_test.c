#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;

void func1()
{
	printf("locking in func1 for th1\n");
	pthread_mutex_lock(&mutex);
	printf("mutex locked and waiting\n");
	pthread_cond_wait(&cond,&mutex);
	printf("waiting done\n");
	printf("msg is heloo manu\n");
        printf("exit from func1\n");
	pthread_mutex_unlock(&mutex);	
}

void func2()
{
        printf("locking in func2 for th2\n");
        pthread_mutex_lock(&mutex);
        printf("mutex locked and sending slg\n");
        pthread_cond_signal(&cond);
        printf("slg sent from func2\n");
        printf("exit from func2\n");
        pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t th1,th2;
	printf("pthread th1 creating\n");
	pthread_create(&th1,NULL,func1,NULL);
	printf("pthread th1 created and creating th2\n");	
	pthread_create(&th2,NULL,func2,NULL);		
        printf("pthread th2 created and joining th1\n");
	pthread_join(th1,NULL);
        printf("pthread th1 joined and joining th2\n");
	pthread_join(th2,NULL);
        printf("pthread th1 joined th2\n");
}
