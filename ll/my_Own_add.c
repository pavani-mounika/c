#include<stdio.h>
#include<stdlib.h>

int main()
{
	int  *p = NULL;
	p= (int *) 0x8000000;
	*p = 0x1234;
	printf("%p %d\n",p,*p);
}
