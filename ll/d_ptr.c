#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r,c,**arr,i,j;
	
	printf("enter no. of r and c\n");
	scanf("%d %d",&r,&c);
	
	arr = (int **)malloc(sizeof(int *) * r);
	
	for(i=0;i<r;i++)
		arr[i] = (int *)malloc(sizeof(int) * c);
	
	printf("\nenter array elements\n");

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}	
	}	
	printf("\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",*(*(arr+i)+j));
		}
		printf("\n");
	}
	free(arr);
}
