#include <stdio.h>
#include <stdlib.h>

int arr_recursive(unsigned char arr[], unsigned char first , unsigned char last)
{
    // Base case: if first index is greater than or equal to last index, return
    if (first >= last)
    {
        return 0; // Base case reached, no more swaps needed
    }
    unsigned int temp;
    temp = arr[first];
    arr[first] = arr[last];
    arr[last] = temp;
    // Print the current state of the array after each swap
    printf("Swapped: %d with %d\n", arr[first], arr[last]);

    // Recursive call to continue swapping until the base case is reached
    // Base case: if first index is less than last index, continue recursion
    if (first < last)
    {
        // Increment first index and decrement last index for the next call
        arr_recursive(arr,++first,--last);
    }


}

int main()
{
    unsigned int i;
    unsigned char arr[7] = {90,20,100,40,50,60};
    arr_recursive(arr,0,5);
    for (i=0;i<6;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}

// This code defines a recursive function to reverse an array of unsigned characters.
// The function `arr_recursive` takes an array and two indices, `first` and `last`, and swaps the elements at these indices.
// The recursion continues until `first` is greater than `last`, at which point the function returns.