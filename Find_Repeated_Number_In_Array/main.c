#include <stdio.h>
#include <stdlib.h>

// Function prototype for finding the first repeated element in an array
// If no repeated element is found, it returns -1
int repeated(int arr[]);
void find_smallest(int arr[], int arr_size);

int main()
{
    unsigned int i;
    unsigned int arr[20];
    unsigned int ret;
    for (i=0;i<20;i++)
    {
        arr[i]=i;
    }
    arr[10]=9;
    ret = repeated(arr);
    printf("%d\n",ret);
    find_smallest(arr, 20);

    return 0;
}

// Function to find the first repeated element in an array of 20 integers
// If no repeated element is found, it returns -1
int repeated(int arr[])
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = i + 1; j < 20; j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }
    return -1; // Return -1 if no repeated element is found
}

void find_smallest(int arr[], int arr_size)
{
    int i;
    unsigned int smallest=0xFFFFFFFF; // Initialize smallest to a large value
    for (i=0;i<arr_size;i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    printf("smallest is : %d\n",smallest);
}