#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void add(struct node **q,int val)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	if(*q!=NULL)
		temp->next=(*q);
	*q=temp;
}

void dis(struct node **q)
{
	struct node *temp=NULL;
	temp=*q;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}

void rev(struct node **q)
{
	struct node *next=NULL;
	struct node *prev=NULL;
	struct node *current=NULL;
	current = *q;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*q=prev;
}	

int main()
{
	struct node *p;
	int s,val,i;
	printf("enter size\n");
	scanf("%d",&s);
	for(i=0;i<s;i++)
	{
		printf("enter node val\n");
		scanf("%d",&val);
		add(&p,val);
	}
	dis(&p);
	printf("\n");
	rev(&p);
	printf("\n");
	dis(&p);
	printf("\n");
}
