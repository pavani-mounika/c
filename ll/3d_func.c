#include<stdio.h>
#include<stdlib.h>

#define d 2
#define r 2
#define c 2

int func(int ***);

int main()
{
	int arr[d][r][c];
	/*int ***arr;
	 int i,j,k 
	 arr=(int ***)malloc(sizeof(int **)*d);
	  for(i=0;i<d;i++)
	  {
	  arr[i]=(int **)malloc(sizeof(int *)*r);
	  for(j=0;j<r;j++)
	  arr[i][j]=(int *) malloc(sizeof(int)*c);
	  }
	  printf("writing value \n");
	  for(i=0;i<d;i++)
	  {
	  for(j=0;j<r;j++)
	  {
	  for(k=0;k<c;k++)
	  {
	  scanf("%d",&arr[i][j][k]);
	  }
	  }
	  }*/
	func(arr);
	/*	printf("reading value in main\n");
		for(i=0;i<d;i++)
		{
		for(j=0;j<r;j++)
		{
		for(k=0;k<c;k++)
		{
		printf("%d\t",*(*(*(arr+i)+j)+k));
		}
		printf("\n");

		}
		printf("\n");
		}
		printf("\n");
	 */

}

int func(int ***arr)
{
	int i,j,k;
	arr=(int ***)malloc(sizeof(int **)*d);
	for(i=0;i<d;i++)
	{
		arr[i]=(int **)malloc(sizeof(int *)*r);
		for(j=0;j<r;j++)
			arr[i][j]=(int *) malloc(sizeof(int)*c);
	}
	printf("writing value in func\n");
	for(i=0;i<d;i++)
	{
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				scanf("%d",&arr[i][j][k]);
			}
		}
	}

	printf("reading value in func \n");
	for(i=0;i<d;i++)
	{
		for(j=0;j<r;j++)
		{
			for(k=0;k<c;k++)
			{
				printf("%d\t",*(*(*(arr+i)+j)+k));
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("\n");

}
