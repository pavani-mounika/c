#include<stdio.h>
#include<string.h>

int main()
{
	int arr[10],i;
	memset(arr,0,10*sizeof(arr[0]));
	for(i=0;i<10;i++)
		printf("%d\t",arr[i]);
	printf("\n");
	char str[50] = "coding all day make me happy";
	memset(str+6,'.',5*sizeof(char));
	printf("%s\n",str);
}
