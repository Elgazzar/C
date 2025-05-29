#include <stdio.h>
#include <stdlib.h>

void print()
{
    printf("Hello world!\n");
}

int main()
{
    void (*fun_ptr)(void) = print;
    fun_ptr();
    return 0;
}
