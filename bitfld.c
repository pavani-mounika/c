#include<stdio.h>
struct s
{
	int i;
	char c;
	char d;
	char e;
	char f;
	char g;
	char h;
};
struct sb
{
	int i:1;
	char c:1;
	char d:1;
	char e:1;
	char f:1;
	char g:1;
	char h:1;
	char i:1;
	char j:1;
 	char k:1;
};

int main()
{
	struct s o;
	struct sb ob;
	printf("s:%d\n",sizeof(o));
	printf("sb:%d\n",sizeof(ob));
	
}
