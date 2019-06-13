#include<stdio.h>

int main()
{
	char str[100];
	int len=0;
	printf("enter\n");
	scanf("%s",str);
	while(str[len]!='\0')
		len++;
	printf("len:%d\n",len);
}
