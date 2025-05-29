#include <stdio.h>
#include <stdlib.h>

int swap (int *x , int *y);

int main()
{
    // This program swaps two integers using pointers
    // and prints the swapped values.
    // It uses a function to perform the swap operation.
    int a,b;
    printf("Enter two integers: ");
    // Prompt the user to enter two integers
    // Read the integers from standard input
    // and store them in variables a and b
    scanf("%d",&a);
    scanf("%d",&b);
    // Call the swap function to swap the values of a and b
    swap(&a,&b);
    // Print the swapped values
    printf("Swapped values: %d %d\n", a, b);
    return 0;
}

int swap (int *x , int *y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}