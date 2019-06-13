#include<stdio.h>

int main()
{
	int num,r,t=1,res=0;
	printf("enter binary num\n");
	scanf("%d",&num);
	while(num!=0)
	{
		r=num % 10;
		res = res + r*t; 
		t = t * 2;	//for octal *8 and for hex *16
		num = num/10;
	}
	printf("dec:%d\n",res);
}
