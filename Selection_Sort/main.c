#include <stdio.h>
#include <stdlib.h>

void swap_arr(int arr[],int index_A, int index_B);
void Selection_Sort(int arr[],int arr_size);
void print_arr(int arr[],int arr_size);

int main()
{
    int Test_Arr[] = {9,8,7,5,6,4,3,2,1,0};
    Selection_Sort(Test_Arr,10);
    print_arr(Test_Arr,10);
    return 0;
}

void Selection_Sort(int arr[],int arr_size)
{
    int min_elemtnt = 0;
    for(int i =0; i <arr_size; i++ )
    {
        min_elemtnt = i;
        for(int j= i+1; j<arr_size;j++)
        {
            if(arr[j] < arr[min_elemtnt])
            {
                min_elemtnt = j;
            }
        }
        swap_arr(arr,i,min_elemtnt);
    }
}

//function to SWAP Array_Elements
void swap_arr(int arr[],int index_A, int index_B)
{
    int temp = arr[index_A];
    arr[index_A] = arr[index_B];
    arr[index_B] = temp;
}

void print_arr(int arr[],int arr_size)
{
    int index;
    for (index = 0; index< arr_size; index++)
    {
        printf("Array Elemetns are : %d\n",arr[index]);
    }
}