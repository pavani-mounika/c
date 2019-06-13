#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd[2],pid,ppid;
	char tx[100],rx[100];
	printf("enter msg\n");
	scanf("%s",tx);
	pipe(fd);
	pid = fork();

	if(pid == 0)
	{
		printf("child process is writing\n");
		printf("pid:%d\n",getpid());
		printf("ppid:%d\n",getppid());
		write(fd[1],tx,sizeof(tx));
	} 
	else
	{	
		printf("parent process is reading\n");
		read(fd[0],rx,sizeof(tx));
		printf("%s\n",rx);
	}
}
