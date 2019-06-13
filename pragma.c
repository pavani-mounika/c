#include<stdio.h>
#pragma pack(1)

struct s
{
	int i;
	char c;
};

int main()
{
	struct s o;
	o.i = 10;
 	o.c = 'a';
	printf("%d\n",sizeof(o));
}
