#include<stdio.h>
#include<stdlib.h>

#define r 2
#define c 2
int func(int( *)[c]);
int main()
{
	int i,j;


	int (*arr)[c];
	arr = (int (*)[c])malloc(sizeof(int)*r*c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);	
		}
	}
	func(arr);
}

int func(int (*arr)[c])
{
	int i,j;
	for(i=0;i<(r+c);i+=c)
	{
		(*arr)[i] = (*arr)[i]*2;
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",*(*(arr+i)+j));
		}
		printf("\n");
	}
}
