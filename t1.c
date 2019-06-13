#include <stdio.h>
struct person
{
   int age;
   float weight;
};

int main()
{
    struct person *personPtr;


    printf("Enter age:");
    scanf("%d", &personPtr->age);

    printf("Enter weight:");
    scanf("%f", &personPtr->weight);

    printf("Displaying:\n");
    printf("Age: %d\n", personPtr->age);
    printf("weight: %f", personPtr->weight);

    return 0;
}
