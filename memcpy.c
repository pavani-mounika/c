#include<stdio.h>
#include<string.h>

int main()
{
	char str[50] = "coding all the day is a gread fun";
	char str1[50];
	memcpy(str1,str,strlen(str));
	printf("str1:%s\n",str1);
	memcpy(str+10,str1,strlen(str1));
	printf("str:%s\n",str);
}
