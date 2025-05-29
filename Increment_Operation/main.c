#include "stdio.h"
#include "stdint.h"

uint8_t x = 5;

uint8_t Arr[5] = {1,2,3,94,50};

int main()
{
    printf("x = %d\n", x);  // Print the initial value of x == 5
    printf("x++ = %d it is post incrementing print the value and then increments it\n", x++); // Post-increment: prints x then increments it printing 5
    printf("++x = %d Pre-increment: increments x then prints it printing 7\n", ++x);  // Pre-increment: increments x then prints it printing 7
    return 0;
}