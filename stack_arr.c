#include<stdio.h>
#include<stdlib.h>

int i,s,ch,c=1,val;

int create(int *ptr,int val)
{
	static int i=0;	
	if(c>s)
	{
		printf("stack is full\n");
		exit(0);
	}
	ptr[i++] = val;
	c++;
}

int pop(int *ptr)
{
	if(i<0)
	{
		printf("stack is empty\n");
		return 0;
	}
	printf("pop data:%d\n",ptr[--i]);
}

int display(int *ptr)
{
	int j;
	for(j=0;j<i;j++)
		printf("%d\n",ptr[j]);
	printf("\n");
}

int main()
{
	printf("enter max stack nodes\n");
	scanf("%d",&s);
	int arr[s];
	while(1)
	{	
		printf("enter node values\n");
		scanf("%d",&val);
		create(arr,val);
		printf("enter choice 0 for exit 1 for continue\n");
		scanf("%d",&ch);	
		if(ch==0)
			break;
	}
	printf("display\n");
	display(arr);
	pop(arr);
	display(arr);
}
