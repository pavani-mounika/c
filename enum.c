#include<stdio.h>
enum s{i,c};

int main()
{
	enum s a;
	a = i;
//	a = c;
	printf("i:%d\n",a);
}
