#include<stdio.h>

char *rev(char *str)
{
	if(*str!='\0')
		rev(str+1);
	printf("%c",*str);
}

int main()
{
	char str[10];
	printf("enter\n");
	scanf("%[^\n]",str);
	rev(str);
	printf("\n");
}
