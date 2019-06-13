#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
	char tx[100],rx[100];
	printf("enter msg\n");
	scanf("%s",tx);
	int fd;
	fd = open("/dev/dev_cls",0666);
	if(fd<0)
	{
		printf("error in open\n");
		return 0;
	}
	write(fd,tx,sizeof(tx));
	read(fd,rx,sizeof(rx));
	printf("rx:%s\n",rx);
	close(fd);
}
