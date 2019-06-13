#include<stdio.h>
int main()
{
	char str[100]="akhil",len=0,i=0;
	//scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
		len++;
	printf("len:%d\n",len);

	while(len>=0)
	{
		printf("%c",str[len]);
		len--;
	}
	printf("\n");	
}
