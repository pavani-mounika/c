#include<stdio.h>
#include<stdlib.h>

int func(int ***);
int d,r,c;

int main()
{
	printf("enter d r and c\n");
	scanf("%d %d %d",&d,&r,&c);
	int arr[d][r][c];
	func(&arr); 
}

int func(int ***ptr)
{
	int i,j,k,sum=0;
	printf("d:%d r:%d c:%d\n",d,r,c);
	ptr=(int ***)malloc(sizeof(int **)*d);
	for(i=0;i<d;i++)
	{
		ptr[i]=(int **)malloc(sizeof(int *)*r);
		for(j=0;j<c;j++)
		{
			ptr[i][j]=(int *)malloc(sizeof(int)*c);
		}
	}
	printf("enter\n");
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
	for(i=0;i<d;i++)
        {
                for(j=0;j<r;j++)
                {
                        for(k=0;k<c;k++)
                        {
                                sum = sum +*(*(*(ptr+i)+j)+k);
                        }
                }
        }
	printf("sum:%d\n",sum);
}
