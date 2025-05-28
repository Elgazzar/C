#include "stdio.h"
#include "stdint.h"

void Reverse_Array(uint8_t Arr[],uint8_t arr_size);
void prtintf_Array(uint8_t Arr[],uint8_t arr_size);
void Reverse_Array_an_other_way(uint8_t Arr[],uint8_t arr_size);
void Reverse_Array_third_way(uint8_t *Arr,uint8_t arr_size);
// This program reverses an array in two different ways.

uint8_t Array_a[] = {5,4,3,2,1};

int main()
{
    printf("\nArray Before Reversing:\n");
    prtintf_Array(Array_a,5);
    Reverse_Array_third_way(Array_a,5);
    printf("\nArray After Reversing:\n");
    prtintf_Array(Array_a,5);
    return 0;
}

void Reverse_Array(uint8_t Arr[],uint8_t arr_size)
{
    uint8_t index = 0;
    uint8_t temp = 0;
    for(index=0; index<((arr_size/2));index++)
    {
        /*Swap half of the Array*/
        temp = Arr[index];
        Arr[index] = Arr[arr_size - index - 1];
        Arr[arr_size - index - 1] = temp;
    }
}

void Reverse_Array_an_other_way(uint8_t Arr[],uint8_t arr_size)
{
    uint8_t index = 0;
    uint8_t temp = 0;
    uint8_t new_arr[arr_size];
    /*Copy the Array to a new Array*/
    for(index=0; index<arr_size;index++)
    {
        new_arr[index] = Arr[index];
    }
    /*Reverse the Array*/
    for(index=0; index<arr_size;index++)
    {
        Arr[index] = new_arr[arr_size - index - 1];
    }
}

void Reverse_Array_third_way(uint8_t *Arr,uint8_t arr_size)
{
    uint8_t index = 0;
    uint8_t temp = 0;
    for(index=0; index<((arr_size/2));index++)
    {
        /*Swap half of the Array*/
        temp = Arr[index];
        Arr[index] = Arr[arr_size - index - 1];
        Arr[arr_size - index - 1] = temp;
    }
}

void prtintf_Array(uint8_t Arr[],uint8_t arr_size)
{
    uint8_t index = 0;
    uint8_t calc_arr_size = 0;
    for (index = 0; index < arr_size;index++)
    {
        printf("Array Element is : %d\n",Arr[index]);
    }
    calc_arr_size = sizeof(Array_a) / sizeof(Array_a[0]);
    printf("Array Size is : %d\n",calc_arr_size);
}