#include<stdio.h>

int main()
{
	int s,i,res=0;
	printf("enter size\n");
	scanf("%d",&s);
	int arr[s];
	printf("enter hex values\n");
	for(i=0;i<s;i++)
		scanf("%x",&arr[i]);
	for(i=s-1;i>=0;i--)
	{
		res = res<<8;
		res = res|arr[i];
	}
	printf("\ncomb:%x\n",res);
}
