#include<stdio.h>

int main()
{
	int arr[5]={0x10,0x20,0x30,0x40,0x50};
	int i,sum=0;
	for(i=4;i>=0;i--)
	{
		sum = sum<<8;
		printf("arr[%d]:%x\n",i,arr[i]);
		sum=sum|arr[i];
		printf("%x\n",sum);
	}
	printf("%x\n",sum);
}
