#include<stdio.h>

void func(char *str)
{
	if(*str=='\0')
		return;

	func(str+1);
	printf("%c",*str);

}

int main()
{
	char str[100 ];
	printf("enter str\n");
	scanf("%s",str);
	func(str);
	printf("\n");
}
