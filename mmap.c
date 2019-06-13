#include<stdio.h>
#include <sys/mman.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

size_t s = 25;

int main()
{
	int fd;
	char *path = "/tmp/f";
	mkfifo(path,0666);
	char tx[s],rx[s];
	printf("enter\n");
	scanf("%[^\n]",tx);
	
	fd = open(path , 0666);
	if(fd<0)
	{
		perror("open\n");
		return -1;
	}
	mmap(NULL,s,PROT_WRITE,MAP_SHARED,fd,0);
	write(fd,tx,s);
	read(fd,rx,s);
	printf("read:%s\n",rx);
	unlink(path);
}
