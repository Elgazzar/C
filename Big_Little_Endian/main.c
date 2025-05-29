#include <stdio.h>
#include <stdlib.h>

int main()
{
    //4 byte data
    unsigned long data = 0x11223344;
    //assign data at 1 byte pointer
    unsigned char *check_ptr = (unsigned char *) &data;
    //if value at pointer = most signifcant byte then it is little endian
    if(*check_ptr == 0x44)
    {
        printf("little-endian");
    }
    //and the opposite
    else if (*check_ptr == 0x11)
    {
        printf("big-endian");
    }
    return 0;
}
