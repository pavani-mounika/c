#include<stdio.h>
#include<string.h>

int main()
{
        
	char str[100],len=0,i=0;
	scanf("%s",str);
	printf("%s",strrev(str));

        for(i=0;str[i]!='\0';i++)
                len++;

	for(i=len;i>=0;i--)
	{
		printf("%c",str[i]);
	}

	printf("\n");
}
