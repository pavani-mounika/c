#include<stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
#include<sys/shm.h>

key_t key=123;

struct msg
{
	long type;
	char b[100];
}m;

int main()
{
	int msid;
	m.type=1;
	printf("enter msg\n");
	scanf("%s",m.b);
//	strcpy(m.b,"mounika");
	msid=msgget(key, IPC_CREAT);
	printf("msgget after msgget %d\n",msid);
	if(msid<0)
	{
		printf("msgget %d\n",msid);
		return -1;
	}
	int ret=msgsnd(msid,&m,sizeof(m),0);
	printf("msgsnd ret after msgsnd = %d\n",ret);
	if(ret<0)
	{
		printf("msgsnd ret = %d\n",ret);
		return -1;
	}
	printf("snd:%s\n",m.b);
}	
