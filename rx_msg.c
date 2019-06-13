#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

key_t key = 123;

struct msg
{
	long type;
	char b[100];
}m;

int main()
{
	int msid,ret;
	m.type=1;
	msid=msgget(key,0666|IPC_CREAT);
	ret=msgrcv(msid,&m,sizeof(m),1,0);
	if(ret<0)
	{
		printf("msgrcv ret = %d\n",ret);
		return -1;
	}
	printf("msg:%s\n",m.b);
}
