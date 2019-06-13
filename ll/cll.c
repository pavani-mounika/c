#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void create(struct node **q,int val)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *ptr=NULL;
	ptr=*q;
	temp->data=val;
	if(*q==NULL)
	{
		*q=temp;
		temp->next=temp;
	}
	else
	{
		while(ptr->next!=(*q))
			ptr=ptr->next;
		ptr->next=temp;
		temp->next=(*q);
		*q=temp;	
	}
}

void dis(struct node **q)
{
	struct node *ptr=NULL;
	ptr=*q;
	do{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}while(ptr!=*q);
}

void ins(struct node **q,int pos)
{
	int val,i=1;
	struct node *ptr=NULL;
	struct node *temp=NULL;
	ptr=*q;
	temp=ptr->next;
	printf("enter val\n");
	scanf("%d",&val);
	
	while(temp->next!=(*q))
	{
		if(pos==1)
		{
			struct node *t=(struct node *)malloc(sizeof(struct node));
			t->data=val;
			while(temp->next!=(*q))
				temp=temp->next;
			temp->next=t;
			t->next=(*q);
			*q=t;
		}
		else
		{
			for(i=0;i<pos;i++)
			{
				ptr=temp;
				temp=temp->next;
			}	
                        struct node *t=(struct node *)malloc(sizeof(struct node));
			t->data=val;
			t->next=temp->next;
			ptr->next=t;
		}
	}
}

void rem(struct node **q,int val)
{
	struct node *ptr=NULL;
	struct node *temp=NULL;
	ptr=*q;
	temp=ptr->next;
	while(temp!=(*q))
	{
		if(ptr->data==val && ptr==(*q))
		{
			while(temp->next!=(*q))
				temp=temp->next;
			*q=(*q)->next;
			temp->next=(*q);
			free(ptr);
		}
		else if(temp->data==val)
		{
			ptr->next=temp->next;
			free(temp);
		}
		else
		{
			ptr=temp;
			temp=temp->next;
		}
	}
}

int main()
{
	struct node *p;
	int s,val,i;
	printf("enter s and val\n");
	scanf("%d",&s);
	for(i=0;i<s;i++)
	{
		scanf("%d",&val);
		create(&p,val);
	}
	printf("\n");
	dis(&p);
	printf("\n");
	printf("enter pos to ins the val enter from 1\n");
	scanf("%d",&val);
	ins(&p,val);
	dis(&p);
	printf("enter value to be deted\n");
	scanf("%d",&val);
	rem(&p,val);
	dis(&p);
	printf("\n");
}
