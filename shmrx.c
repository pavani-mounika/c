#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>

key_t key = 123;
size_t size = 1024;

int main()
{
	int shmid;
	char *iptr = NULL, *i = NULL;
	shmid = shmget(key,size,0666|IPC_CREAT);
	if(shmid<0)
	{
		perror("shmid\n");
		return -1;
	} 
	
	iptr = shmat(shmid,NULL,0);
	i = iptr;
	//printf("%s\n",i);
	while(*i!='\0')
	{
		printf("%c",*i);
		i++;
	}

	printf("\n");
	*i = '*';
	printf("%s\n",i);
	printf("\n");
	shmdt(iptr);
	return 0;
}
