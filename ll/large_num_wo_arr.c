#include<stdio.h>

int main()
{
	int n,n1,n2,i;
	printf("enter num\n");
	scanf("%d",&n);	
	printf("enter num1\n");
	scanf("%d",&n1);
	for(i=0;i<n;i++)
	{
		printf("enter n2\n");
		scanf("%d",&n2);
		if(n1<n2)
			n1=n2;		
	}	
	printf("large:%d\n",n1);
}
