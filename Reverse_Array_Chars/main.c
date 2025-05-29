#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char i;
    unsigned char j=4;
    char arr[5]={'H','E','L','L','O'};
    char new_arr[5];
    for (i=0;i<5;i++)
    {
        new_arr[j]=arr[i];
        j--;
    }
    for (i=0;i<5;i++)
    {
        printf("%c",new_arr[i]);
    }
    return 0;
}
