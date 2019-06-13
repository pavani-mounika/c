#include<stdio.h>

struct node
{
	char c;
	int i;
};

int main()
{
	struct node *ptr=NULL;
	ptr++;
	printf("%d\n",ptr);
}
