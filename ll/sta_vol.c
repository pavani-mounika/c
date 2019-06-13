#include<stdio.h>

static int i = 10;

int func(volatile int a)
{
	a = a+10+10;
	i = i+10;
	printf("v:%d i:%d\n",a,i);
}

int main()
{
	volatile int v = 10;
	func(v);
	printf("in main():v:%d i:%d\n",v,i);
}
