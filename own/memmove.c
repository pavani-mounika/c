#include<stdio.h>
#include<string.h>

char ownmemmove(char *rx,char* tx,int s)
{
	int i;
	char temp[s];
	for(i=0;i<s;i++)
		temp[i]=tx[i];
	for(i=0;i<s;i++)
		rx[i]=temp[i];
}

int main()
{
	char tx[100],rx[100];
	printf("enter \n");
	scanf("%[^\n]",tx);
	ownmemmove(rx,tx,strlen(tx));
	printf("rx:%s\n",rx);
}
