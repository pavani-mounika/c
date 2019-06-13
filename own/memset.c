#include<stdio.h>

void mymemset(char* ptr,char c,int v)
{
	int i;
	for(i=0;i<v;i++)
		ptr[i] = c;
}

int main()
{
	char str[50] = "coding is fun with c";
	char c;
	printf("enter a char\n");
	scanf("%c",&c);
	int v;
	printf("enter v for rept\n");
	scanf("%d",&v);
	mymemset(str+3,c,v);
	printf("str:%s\n",str);
}	
