#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd[2],pid;
	char *msg="manu";
	char tx[100],rx[100];
	pid = pipe(fd);
	if(pid<0)
	{
		perror("pipe");
		return;
	}
	printf("enter tx data\n");
	scanf("%s",tx);
	write(fd[1],msg,sizeof(msg));
	read(fd[0],rx,sizeof(msg));
	printf("msg from *msg:%s\n",rx);
	write(fd[1],tx,sizeof(tx));
	read(fd[0],rx,sizeof(tx));
	printf("msg from tx:%s\n",rx);
}
