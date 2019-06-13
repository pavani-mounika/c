#include<stdio.h>

char *ownstr(char *main,char *sub)
{
	while(*main!='\0')
	{
		char *str=main;
		char *pat=sub;
		while(*str!='\0' && *pat!='\0' && *str==*pat)
		{
			str++;
			pat++;
		}
		if(*pat=='\0')
			return main;
		main=str+1;		
	}
	printf("substr not found\n");
	return NULL;
}

int main()
{
	char str[50],sub[20];
	printf("Enter string and substring\n");
	scanf("%s %s",str,sub);
	printf("substr:%s\n",ownstr(str,sub));
}
