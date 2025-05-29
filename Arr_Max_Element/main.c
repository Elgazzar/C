#include "stdio.h"
#include "stdint.h"

void printArray(uint8_t *arr,uint8_t size);
int Get_Arr_Max(uint8_t *Arr,uint8_t size);

uint8_t Arr[5] = {1,2,3,94,50};

int main()
{
    // Print the initial array
    printArray(Arr,5);
    // This function will return the maximum value in the array
    uint8_t max = Get_Arr_Max(Arr,5);
    // Print the maximum value found in the array
    // The maximum value is 94 in this case
    // The function iterates through the array and compares each element to find the maximum value
    // It returns the maximum value found in the array
    printf("Max of the array is : %d\n", max);
    return 0;
}


// This function takes an array of unsigned 8-bit integers and its size as input
// and returns the maximum value found in the array.
// It iterates through the array, comparing each element to find the maximum value.
int Get_Arr_Max(uint8_t *Arr,uint8_t size)
{
    uint8_t index;
    uint8_t max = 0;

    for(index = 0;index <size; index++)
    {
        if(Arr[index] > max)
        {
            max = Arr[index];
        }
    }
    return max;
}
//define a function that prints the elements of the array
// This function takes an array of unsigned 8-bit integers and its size as input
// and prints each element of the array along with its index.
void printArray(uint8_t *arr,uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        printf("Array Element %d is : %d\n", i , arr[i]);
    }
    printf("\n");
}