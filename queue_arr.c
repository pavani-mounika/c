#include<stdio.h>
#include<stdlib.h>

int front=0,rear=0,s;

int queue(int *ptr,int val)
{
	if(rear>s)
	{
		printf("queue is full\n");
		return 0;
	}
	ptr[rear]=val;
	rear++;
}

int dequeue(int *ptr)
{
	if(front>rear)
	{
		printf("queue is empty\n");
		return 0;
	}
	printf("dequeue data:%d\n",ptr[front]);
	front++;
}

void display(int *ptr)
{
	int i;
	for(i=0;i<rear;i++)
		printf("%d\n",ptr[i]);
	printf("\n");
}

int main()
{
	int ch,i,val;
	printf("enter size\n");
	scanf("%d",&s);
	int arr[s];
	up:while(1)
	{
		printf("enter choice 0 for exit 1 for continue\n");
		scanf("%d",&ch);
		if(ch==0)
			break;
		printf("enter array elements\n");
		scanf("%d",&val);
		queue(arr,val);
	}
	printf("display data\n");
	display(arr);
	printf("enter choice 0 for exit 1 for dequeue\n");
	scanf("%d",&ch);
	if(ch==1)
		dequeue(arr);
	printf("display after deqeue");
	display(arr);
	printf("0 for exit else any key\n");	
	scanf("%d",&ch);
	if(ch==0)
		exit(0);
	else
		goto up;
}
