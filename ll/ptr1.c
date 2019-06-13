#include<stdio.h>
int main()
{
	int x = 20,*y,*z;
	y=&x;
	z=y;
	printf("y:%d\n",*y++);
	printf("z:%d\n",*z++);
	printf("x:%p\n",x++);
        printf("z:%d\t y:%d\t x:%p\n",*z,*y,x);
}
