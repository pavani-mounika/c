#include<stdio.h>

int main()
{
	volatile const int a = 10;
	volatile *ptr = NULL;
	ptr = &a;
	printf("val : %d\n",*ptr);
	*ptr = 15;
	printf("val:%d\n",*ptr);
}	
