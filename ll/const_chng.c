#include<stdio.h>

int main()
{
	int const num = 10;
	int *ptr = NULL;
	printf("before change:%d\n",num);
	ptr = &num;
	*ptr = 20;
	printf("after change:%d\n",*ptr);
}
