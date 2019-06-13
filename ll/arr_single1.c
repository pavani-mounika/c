#include<stdio.h>

int main()
{
	int s,i,r=0,c,d;
	printf("enter s\n");
	scanf("%d",&s);
	int arr[s];
	printf("enter array elements in hex\n");
	for(i=0;i<s;i++)
		scanf("%x",&arr[i]);
	for(i=s-1;i>0;i--)
	{
		r=r<<8;
		c=arr[i]<<4;
		d=arr[i]>>4;
		arr[i]=c|d;
		r=r|arr[i];	
	}
	printf("%x\n",r);
}
