#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int arr[],int size);
// This program demonstrates how to reverse an array using bubble sort.
// The array is sorted in descending order, effectively reversing it.
// The bubble sort algorithm repeatedly steps through the list, compares adjacent elements,
// and swaps them if they are in the wrong order. The process is repeated until the array is sorted.
// The time complexity of bubble sort is O(n^2) in the worst case, making it inefficient for large datasets.
int Arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};


int main()
{
    printf("Reverse the array using bubble sort:\n");
    bubbleSort(Arr,10);
    // Print the reversed array
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", Arr[i]);
    }
    return 0;
}

void bubbleSort(int arr[],int size)
{
    int i,j;
        for (i = 0; i<size;i++)
        {
            for(j=0;j<size-1;j++)
            {
                if(arr[j] > arr[j+1])
                {
                    // Swap the elements
                    // Using a temporary variable to hold the value
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
}