#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	char buf[100],rx[100];
	printf("enter msg\n");
	scanf("%s",buf);
	int fd;
	fd = open("/dev/manu_cdrv",0666);
	if(fd<0)
	{
		printf("error in open\n");
		return 0;
	}
	write(fd,buf,sizeof(buf));
	read(fd,rx,sizeof(rx));
	printf("rx:%s\n",rx);
	return 0;
}
