#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<sys/ioctl.h>
 
#define WR_VALUE _IOW('a','a',char*)
#define RD_VALUE _IOR('a','b',char*)
#define MAX 40
int main()
{
        int fd;
        char send[MAX], rx[MAX];
         
        printf("\nOpening Driver\n");
        fd = open("/dev/srinivas", O_RDWR);
        if(fd < 0) {
                printf("Cannot open device file...\n");
                return 0;
        }
 
        printf("Enter the msg to send\n");
        scanf("%s",send);
        printf("Writing Value to Driver\n");
        ioctl(fd, WR_VALUE,send); 
 
        printf("Reading Value from Driver\n");
        ioctl(fd, RD_VALUE,rx);
        printf("rx is %s\n",rx);
 
        printf("Closing Driver\n");
        close(fd);
}
