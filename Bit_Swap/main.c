#include <stdio.h>
#include <stdlib.h>

/*if you have two numbers how many swaps in bits that make first number equals the second number*/

int main()
{
    //0b010101
    //0b111010
    unsigned char a=0b010101;
    unsigned char b=0b111010;
    unsigned char count=0;

    
    while (a != b)
    {
        printf(" ~b & 0x1 = : %d\n", (~b & 0x1));
        printf("~a & 0x1 = : %d\n", (~a & 0x1));

        // Check the least significant bit of both numbers
        // If they are different, increment the count
        if (((a & 0x1 ==1) && (~b & 0x1 == 1)) || ((~a & 0x1 ==1) && (b & 0x1 == 1)))
        {
            // Increment the count if the bits are different
            // This means we need to swap this bit
            // to make the two numbers equal
            count++;
        }
        // Right shift both numbers to check the next bit
        // This effectively moves to the next bit in the binary representation
        // Note: The right shift operator (>>) shifts bits to the right
        // and fills the leftmost bits with zeros
        // This is equivalent to dividing the number by 2
        (a=(a>>1));
        (b=(b>>1));
    }
    printf("%d",count);
}
