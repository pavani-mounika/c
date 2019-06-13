#include<stdio.h>
int main()
{
	char str[100],str1[100],i,j,len1=0,len2=0;
	printf("enter\n");
	scanf("%s %s",str,str1);
	for(i=0;str[i]!='\0';i++)
		len1++;

	for(i=0;str1[i]!='\0';i++)
		len2++;

	if(len1!=len2)
	{
		printf("string not same\n");
		return;
	}
	else
	{
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i] != str1[i])
			{
				printf("string not same\n");
				return;
			}
		
		}
		printf("strings are same\n");
	}
}
