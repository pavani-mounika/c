#include<stdio.h>
int r=2,c=2;

int func(int arr[r][c])
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			printf("%d\n",arr[i][j]);
}

int main()
{
	int arr[r][c];
	int i,j;
	printf("enter\n");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&arr[i][j]);
	func(arr);
}
