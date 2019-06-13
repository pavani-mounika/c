#include<stdio.h>
#include<string.h>

int main()
{
	char str[10]="manusree";
	int i,j,l;
	l=strlen(str);
	printf("l:%d\n",l);
	for(i=0,j=l-1;i<j;i++,j--)
	{
		str[i]=str[i]+str[j];
		str[j]=str[i]-str[j];
		str[i]=str[i]-str[j];
		printf("%c\n",str[i]);
	}
	printf("%s\n",str);
}
