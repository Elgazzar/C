#include "stdio.h"
#include "stdint.h"

#define Bit_0 0
#define Bit_1 1
#define Bit_2 2
#define Bit_3 3
#define Bit_4 4
#define Bit_5 5
#define Bit_6 6
#define Bit_7 7
#define Num_Bits 8

void Set_Bit(uint8_t *Port_Number, uint8_t Bit_Number)
{
    *Port_Number |= (1 << Bit_Number);
}

void Clear_Bit(uint8_t *Port_Number, uint8_t Bit_Number)
{
    *Port_Number &= (~(1 << Bit_Number));
}

void Toggle_Bit(uint8_t *Port_Number, uint8_t Bit_Number)
{
    *Port_Number ^= ((1 << Bit_Number));
}

void print_uint8_binary(uint8_t value) {
    printf("Binary representation of %u: ", value);
    
    // Start with the most significant bit (bit 7)
    for (int i = 7; i >= 0; i--) {
        // Check if bit i is set using bitwise AND with (1 << i)
        if (value & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

uint8_t Port_A = 0;
uint8_t i;

void main()
{
    Set_Bit(&Port_A,Bit_0);
    Set_Bit(&Port_A,Bit_1);
    Set_Bit(&Port_A,Bit_2);
    Set_Bit(&Port_A,Bit_3);
    Set_Bit(&Port_A,Bit_4);
    Set_Bit(&Port_A,Bit_5);
    Set_Bit(&Port_A,Bit_6);
    Set_Bit(&Port_A,Bit_7);

    for(i=0; i<Num_Bits;i++)
    {
        Clear_Bit(&Port_A,i);
        printf("Port A is : %d After Clearing Bit Number : %d \n",Port_A ,i);
        print_uint8_binary(Port_A);
    }

    printf("===========================================================================\n");
    Toggle_Bit(&Port_A,Bit_0);
    printf("Port A is : %d After Toogling Bit Number : %d \n",Port_A ,Bit_0);
    Toggle_Bit(&Port_A,Bit_0);
    printf("Port A is : %d After Toogling Bit Number : %d \n",Port_A ,Bit_0);
    Toggle_Bit(&Port_A,Bit_0);
    printf("Port A is : %d After Toogling Bit Number : %d \n",Port_A ,Bit_0);
    Toggle_Bit(&Port_A,Bit_0);
    printf("Port A is : %d After Toogling Bit Number : %d \n",Port_A ,Bit_0);

}