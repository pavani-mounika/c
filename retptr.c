#include<stdio.h>

int *add(int x,int y)
{
        printf("in add\n");
	int *p = NULL;
	int z = x+y;
	p = &z;
	printf("p:%d\n",*p);
	return p;
}

int main()
{
	int a=10,b=20;
	int *p = NULL;
	p = add(a,b);
	printf("p:%d\n",*p);
}
