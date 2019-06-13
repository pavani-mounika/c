#include<stdio.h>

int main()
{
	int a[7]={1,2,3,4,5,6,7};
	int *b=NULL;
	b=&a;
	b++;
	b++;
	printf("%d\n",*b);
}
