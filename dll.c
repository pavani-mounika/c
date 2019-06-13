#include<stdio.h>
#include<stdlib.h>

static int c=0;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};


void beg(struct node **q,int val)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->prev=NULL;
	temp->next=NULL;
	c++;
	if(*q!=NULL)
	{
		temp->next=*q;
		(*q)->prev=temp;
	}
	*q=temp;
}

void end(struct node **q,int val)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *ptr=NULL;
	ptr=*q;
	temp->data=val;
	c++;
	if(*q==NULL)
	{
		temp->next=NULL;
		temp->prev=NULL;
		*q=temp;
	}
	else
	{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
		temp->prev=ptr;
		temp->next=NULL;	
	}
}

void dis(struct node **q)
{
	struct node *ptr = NULL;
	printf("\n%d\n\n",c);
	ptr=*q;
	struct node *temp = NULL;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		temp=ptr;
		ptr=ptr->next;
	}
	printf("\nreverse\n");
	while(temp!=(*q))
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}	
	printf("%d",temp->data);
}

void ins(struct node **q,int pos)
{
	struct node *ptr = NULL;
	int i,val;
	ptr=*q;
	printf("enter val\n");
	scanf("%d",&val);
	/*if(pos==0)
	  {
	  printf("pos=0");
	  struct node *temp=(struct node *)malloc(sizeof(struct node));
	  temp->data=val;
	  temp->prev=NULL;
	  temp->next=(*q);
	  (*q)->prev=temp;
	  temp=(*q);
	  }
	  else if(pos==c-1)
	  {
	  printf("elseif:%d\n",pos);
	  for(i=0;i<pos;i++)
	  ptr=ptr->next;
	  struct node *temp=(struct node *)malloc(sizeof(struct node));
	  temp->data=val;
	  temp->next=ptr->next;
	  temp->prev=ptr;
	  ptr->next=temp;
	  temp->next->prev=temp;

	  }
	  else{*/	
	printf("else:%d",pos);
	for(i=0;i<pos;i++)
		ptr=ptr->next;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=ptr->next;
	temp->prev=ptr;
	ptr->next=temp;
	temp->next->prev=temp;	
	//}
}

void rm(struct node **q,int pos)
{
	struct node *temp=NULL;
	struct node *ptr=NULL;
	temp=*q;
	ptr=*q;
	int i;
	if(pos==0)
	{
		(*q)=(*q)->next;
		free(temp);
	}
	else if(pos==c)
	{
		for(i=0;i<pos;i++)
		{
			ptr=temp;
			temp=temp->next;
		}	
		ptr->next=temp->next;
		free(temp);
	}
	else
	{
		for(i=0;i<pos;i++)
		{
			ptr=temp;
			temp=temp->next;
		} 
		ptr=temp->next;
		free(temp);

	}
}

int main()
{
	struct node *p;
	int s,i,val,op;
	printf("enters and vals\n");
	scanf("%d",&s);

	printf("1 for beg 0 for end\n");
	scanf("%d",&op);
	switch(op)
	{
		case 1:for(i=0;i<s;i++)
		       {
			       scanf("%d",&val);
			       beg(&p,val);				
		       }
		       break;
		case 0:for(i=0;i<s;i++)
		       {
			       scanf("%d",&val);                        
			       end(&p,val);
		       }
		       break;
		default:printf("wrong option\n");
			break;
	}
	printf("\n");
	dis(&p);
	printf("\n");
	printf("enter pos for insertion \n");
	scanf("%d",&val);
	if(c<val)
	{
		printf("value is more\n");
		return;
	}
	ins(&p,val);
	dis(&p);
	printf("\n");
	printf("enter pos for deletion \n");
	scanf("%d",&val);
	rm(&p,val);
	dis(&p);
}
