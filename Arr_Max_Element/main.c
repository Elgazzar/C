#include "stdio.h"
#include "stdint.h"

void printArray(uint8_t *arr,uint8_t size);
int Get_Arr_Max(uint8_t *Arr,uint8_t size);

uint8_t Arr[5] = {1,2,3,94,50};

int main()
{
    printArray(Arr,5);
    //get max of the array 
    uint8_t max = Get_Arr_Max(Arr,5);
    printf("Max of the array is : %d\n", max);
    return 0;
}


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
void printArray(uint8_t *arr,uint8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        printf("Array Element %d is : %d\n", i , arr[i]);
    }
    printf("\n");
}