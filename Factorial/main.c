#include <stdio.h>
#include <stdlib.h>


//factorial(5) == 5 * factorial(4)
// factorial(4) == 4 * factorial(3)
// factorial(3) == 3 * factorial(2)
// factorial(2) == 2 * factorial(1)
// factorial(1) == 1 * factorial(0)
// factorial(0) == 1
unsigned short int factorial( unsigned short int n)
{
    if ( n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    unsigned short int number = 5; // Example input
    unsigned short int result = factorial(number);
    printf("Factorial of %d is %d\n", number, result);
    return 0;
}