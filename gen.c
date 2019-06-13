#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void gen(struct node **q,int val)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	if(q!=NULL)
	{
		temp->next=(*q);
	}
	*q=temp;	
}

void dis(struct node **q)
{
	struct node *ptr=NULL;
	ptr=*q;
	int opt;
        printf("enter option: 1 for int,2 for float, 3 for char\n");
        scanf("%d",&opt);
        switch(opt)
        {
  		case 1:while(ptr!=NULL)
			{
				printf("%d\t",ptr->data);
				ptr=ptr->next;
			}
			break;
                case 2:while(ptr!=NULL)
                        {
                                printf("%f\t",(float)ptr->data);
                                ptr=ptr->next;
                        }
                        break;
                case 3:while(ptr!=NULL)
                        {
                                printf("%c\t",(char)ptr->data);
                                ptr=ptr->next;
                        }
                        break;
		default: printf("wrong option\n");
			 break;
	}
}

int main()
{
	struct node *p=NULL;
	int s,val,i;
	printf("enter size\n");
	scanf("%d",&s);
	printf("enter val for each node :\n");
	for(i=0;i<s;i++)
	{
		scanf("%d",&val);
		gen(&p,val);
	}
	dis(&p);
	printf("\n");
}
