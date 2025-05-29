#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 5;
    // Pointer to a const int
    const int *xptr = &x;

    //const pointer to an int
    int *const xptr2 = &x;

    //*xptr = 10; // This line will cause a compilation error
    // because xptr is a pointer to a const int, meaning the value it points to cannot be modified.



    //xptr2++; // This line will cause a compilation error
    // because xptr2 is a const pointer to an int, meaning the pointer itself cannot be modified.

    printf("%d\n", *xptr);
    return 0;
}