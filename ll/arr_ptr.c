#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r,c,i,j;

	printf("enter r anc c\n");
	scanf("%d %d",&r,&c);
	
	int *arr[r];
		
	for(i=0;i<r;i++)
		arr[i]=(int *)malloc(sizeof(int)*c);
	
	printf("\n enter elements\n");
	
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
