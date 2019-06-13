//void * memcpy(void * destination, const void * source, size_t num);
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mymemcpy(void *rx,void *tx,size_t s)
{
	int i;
	char *dest = (char *)rx;
	char *src = (char *)tx;
	for(i=0;i<s;i++)
		dest[i]=src[i];
}

int main()
{
	char tx[100],rx[100];
	printf("enter any msg\n");
	scanf("%[^\n]",tx);
	mymemcpy(rx,tx,strlen(tx));
	printf("%s\n",rx);
}
