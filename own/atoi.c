#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int atoi(const char *nptr);
int func(char *str)
{
        int i,l,res=0;
	
        l=strlen(str);

        for(i=0;i<l;i++)
                res=res*10+str[i]-'0';  //res*10+str[i] - 30(ascii value where num stats from 30-0,31-1...
	printf("res:%d\n",res);
        return res;
}

int main()
{
        char str[10];
        printf("entering num as string\n");
        scanf("%s",str);
        int r=func(str);
        printf("in main:%d\n",r);
}

