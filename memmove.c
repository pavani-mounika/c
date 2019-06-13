#include<stdio.h>
#include<string.h>

int main()
{
	char str1[20] = "coding is fun";
	char str2[20];
	memmove(str2,str1,strlen(str1));
	printf("str2:%s\n",str2);
	memmove(str1+9,str2,strlen(str2));
	printf("str1:%s\n",str1);
	
char csrc[100] = "Geeksfor"; 
memcpy(csrc+5, csrc, strlen(csrc)+1); 
printf("memcpy:%s\n", csrc); 
csrc[100] = "Geeksfor";
memmove(csrc+5, csrc, strlen(csrc)+1);
printf("memmove:%s\n", csrc);
  

}
