#include<stdio.h>
#include<stdlib.h>

#define R 3
#define C 3
int func(int(*)[C]);
int main()
{
	int i,j;
	int (*arr)[C];
	arr = (int (*)[C])malloc(sizeof(int)*R*C);
	printf("enter \n");
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	func(arr);
}

int func(int (*arr)[C])
{
	int j;
	printf("reading 1st col\n");
	for(j=0;j<C;j++)
	{
		printf("%d\n",*(*(arr+0)+0));
		arr++;
	}
}
