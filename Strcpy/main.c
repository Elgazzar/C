#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype for finding the first repeated element in an array
void str_copy(char s1[],char s2[]);

int main()
{
    char str1[15];
    char str2[15] = "Embedded C";
    
    // Copying the string from str2 to str1
    //strcpy(str1, str2); // Using the standard library function
    str_copy(str1,str2); // Using the custom function defined below
    
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
    return 0;
}
void str_copy(char s1[],char s2[])
{
    int i =0;
    while(s2[i]!= '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    //put null terminator
    s1[i]=s2[i];

}
