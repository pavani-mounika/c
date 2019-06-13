#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned int x = 0x456112;
	char *ptr = (char *)&x;
	printf("char size:%d\n",sizeof(ptr));
	printf("%x",*ptr);
	if(*ptr == 0x12)
		printf("little endian\n");
	else
		printf("big endian\n");
}
