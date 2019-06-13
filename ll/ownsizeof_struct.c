#include<stdio.h>

struct s
{
	int i;
	char c;
};

int main()
{
	struct s *ptr=NULL;
	ptr++;
	printf("%d\n",ptr); 	
}
