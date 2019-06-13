#include<stdio.h>
#include<stdlib.h>

int d,r,c;

int func(int ***ptr)
{
	int i,j,k;
	int temp[1][r][c];
	ptr=(int ***)malloc(sizeof(int **)*d);
	for(i=0;i<d;i++)
	{
		ptr[i]=(int **)malloc(sizeof(int *)*r);
		for(j=0;j<r;j++)
			ptr[i][j]=(int *) malloc(sizeof(int)*c);
	}

	printf("done memory allocation and write\n");

	for(i=0;i<d;i++)
	{
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				scanf("%d",&ptr[i][j][k]);
			}
		}
	}

	for(j=0;j<r;j++)
	{
		for(k=0;k<c;k++)
		{
			temp[0][j][k]=ptr[1][j][k];
		}
	}
	for(j=0;j<r;j++)
	{
		for(k=0;k<c;k++)
		{
			ptr[1][j][k]=ptr[0][j][k];
		}
	}
	for(j=0;j<r;j++)
	{
		for(k=0;k<c;k++)
		{
			ptr[0][j][k]=ptr[2][j][k];
		}

	}
	for(j=0;j<r;j++)
	{
		for(k=0;k<c;k++)
		{
			ptr[2][j][k]=temp[0][j][k];
		}
	}
	printf("after rev\n");
	for(i=0;i<d;i++)
	{
		for(j=0;j<r;i++)
		{
			for(k=0;k<c;k++)
			{
				printf("%d\t",*(*(*(ptr+i)+j)+k));
			}
			printf("\n");
		}
	}
}

int main()
{
	printf("enter d,r,c\n");
	scanf("%d %d %d",&d,&r,&c);
	int arr[d][r][c];
	func(arr);
}
