#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	char rx[100];
	char *path="/tmp/fifo";
	int fd=mkfifo(path,0666);
	if(fd<0)
	{		
		printf("mkfifo\n");
		return -1;	
	}	
	fd = open(path,O_WRONLY);
	if(fd<0)
	{
		printf("open in rx");
		return -1;
	}
	read(fd,rx,strlen(rx));
	printf("%s\n",rx);
	unlink(path);
}	
