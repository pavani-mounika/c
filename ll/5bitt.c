#include<stdio.h>

int main()
{
	int i=0,num,t=16;
	printf("enter num\n");
	scanf("%d",&num);
	while(i<4)
	{
		num=num^t;
		printf("%d\n",num);
		t=t<<5;
		i++;
	}
	printf("num:%x\n",num);
}
