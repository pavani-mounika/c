#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	char tx[100];
	char *path ="/tmp/fifo";
	printf("enter sting\n");
	scanf("%s",tx);
	int fd=mkfifo(path,0666);
	if(fd<0)
	{
		printf("mkfifo");
		return -1;
	}
	 fd = open(path,0666);
	if(fd<0)
	{
		printf("open\n");
		return -1;
	}
	write(fd,tx,strlen(tx));
	unlink(path);
}
