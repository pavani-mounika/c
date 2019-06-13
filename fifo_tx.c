
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	int fd;
	char * myfifo = "/tmp/myfifo"; 
	mkfifo(myfifo, 0666); 

	char arr1[80];
	fd = open(myfifo, O_WRONLY); 

	printf("enter\n");
	scanf("%s",arr1); 
	write(fd, arr1, sizeof(arr1)); 
	close(fd);
	return 0; 
} 

