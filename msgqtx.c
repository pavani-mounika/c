#include<stdio.h>
#include<setjmp.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
#define KEY 15
struct msg
{
	long int type;
	char msg[20];
};
int main()
{
 	struct msg message;
	int qid,n;
	qid=msgget(KEY,0666|IPC_CREAT);
	if(qid<0)
	{
		perror("msgget");
		exit(0);
	}
	else
	{
		printf("created\n");
	}
	message.type=7;
//	strcpy(message.msg,"manusrre");
	printf("enter msg\n");
	scanf("%s",message.msg);
	if((n=msgsnd(qid,&message,20,0)<0))
	{
		perror("msgsnd");
		exit(0);
	}
 	printf("%d\n",n);
	printf("sent\n");
}
