#include<stdio.h>

int main()
{
	int num,i=2,c,j,temp=0,d,d1;
	int check=0;
	printf("enter num\n");
	scanf("%d",&num);
	int arr[num];
	while(1)
	{
		c=0;
		for(j=1;j<i;j++)
		{
			if(i%j==0)
				c++;
		}
		if(c<=2)
		{
			arr[temp]=i;
			temp++;
		}
		if(temp>num)
			break;
		i++;	
	}
	
	for(i=0;arr[i]<num;)
	{
		if(arr[i]<num)
		{
			d=num-arr[i];
			d1=num-arr[++i];
			if(d1<0)
				d1=(-1)*d1;
		}
	}
	if(d<d1)
		printf("nearest prime:%d\n",arr[--i]);
	else
		printf("nearest prime:%d\n",arr[i]);
}
