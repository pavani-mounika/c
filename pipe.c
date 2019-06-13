#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd[2];
	int r = pipe(fd);

	char msg[10],buf[10];
	printf("enter\n");
	scanf("%s",msg);
	int ret = fork();
	if(ret<0 && r<0)
	{
		printf("child and pipe not process cretaed\n");
		return -1;
	}
	if(ret==0)
	{
		printf("child process\n");
		write(fd[1],msg,strlen(msg));
	}
	else
	{
		printf("parent process\n");
		read(fd[0],buf,strlen(buf));
		printf("read:%s\n",buf);
	}
}		
