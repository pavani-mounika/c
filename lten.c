#include<stdio.h>

int main()
{
	int x = 0x10203040;
	char *cptr = (char *)&x;
	if(*cptr == 0x40)
		printf("little endian\n");
	else
		printf("big endian\n");
}
