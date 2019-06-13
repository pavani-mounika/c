#include<stdio.h>

int main()
{
	int c;
	printf("%d\n",(int)(&c+1)-(int)(&c));
}
