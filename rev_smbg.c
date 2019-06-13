#include<stdio.h>
int main()
{
	char str[100],i;
	printf("enter string\n");
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>96 && str[i]<123)
			str[i]=str[i]-32;
		else if(str[i]>64 && str[i]<91)
			str[i]=str[i]+32;	
	}
	printf("%s\n",str);
}
