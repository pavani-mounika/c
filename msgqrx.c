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
	if((n=msgrcv(qid,&message,20,7,0)>0))
	{
		printf("in if loop\n");
		printf("received msg::%s\n",message.msg);
	}
	else
	{
		printf("not received\n");
	}
}
