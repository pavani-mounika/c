#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r,c,i,j;
	printf("enter r and c\n");
	scanf("%d %d",&r,&c);
	
	int (*ptr)[c];
	ptr = (int(*)[c])malloc(sizeof(int)*r*c);
	
	printf("\nenter array elements\n");
	
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&ptr[i][j]);
		}
	}

        printf("\n");
	
//	printf("%d\n",*(*(ptr+0)+0));
//	ptr++;
//      printf("%d\n",*(*(ptr+0)+0));

	for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        printf("%d\t",*(*(ptr+i)+j));
                }
		printf("\n");
        }
	printf("\n");
	free(ptr);
}
