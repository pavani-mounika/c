#include <stdio.h>
struct emp
{
   int id;
};

int main()
{
    struct emp *e;
 
    printf("Enter id:");
    scanf("%d", &e->id);


    printf("Displaying:\n");
    printf("Age: %d\n", e->id);

    return 0;
}
