#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

key_t key = 123;
size_t size = 1024;

int main()
{
	char str[100],c;
	char *s;
	//printf("enter msg:");
	//scanf("%s",str);
	int ret,shmid;
	shmid = shmget(key,size,0666|IPC_CREAT);
	if(shmid<0)
	{
		perror("shmid\n");
		return -1;
	}

	char *ptr = shmat(shmid,NULL,0);
	
	if(ptr==NULL)
	{
		perror("shmat\n");
		return -1;
	}		
	
	s = ptr;
	for(c='a'; c<='z';c++)
		*s++ = c;
	*s = '\0';
	while(*s!='*')
	{
		sleep(1);
		printf("waiting to read\n");
	}
	printf("read data\n");
	shmdt(ptr);
	return 0;
}
