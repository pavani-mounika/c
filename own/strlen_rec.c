#include<stdio.h>
int c=0;

int len(char *str)
{
	if(*str!='\0')
	{
		c++;	
		len(str+1);
	}
	return c;
}

int main()
{
	char str[10];
	printf("enter\n");
	scanf("%s",str);
	printf("len:%d\n",len(str));
}
