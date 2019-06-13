#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main()
{
	int *ptr = NULL;
	
	ptr = (int *)calloc(2,sizeof(int));
	ptr = (int *)malloc(sizeof(int));
	malloc_stats();
}
