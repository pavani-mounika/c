#include<stdio.h>
int main()
{
	char str[100],str1[100],i,j=0,len=0;
	
	printf("enter string\n");
	scanf("%s %s",str,str1);
	
	for(i=0;str[i]!='\0';i++)
		len++;
	for(i=len;str1[i]!='0';i++)
	{
		str[i] = str1[j];
		j++;
	}
	printf("%s\n",str);
}
