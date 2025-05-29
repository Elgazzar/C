#include <stdio.h>
#include <stdlib.h>


void print_triangle_pattern();  // Function prototype for printing the triangle pattern
void draw_x();  // Function prototype for drawing the 'X' pattern
void draw_line(); // Function prototype for drawing a line
void draw_xx(); // Function prototype for drawing another 'X' pattern

int main()
{
    // Call the function to print the triangle pattern
    print_triangle_pattern();
    draw_line(); // Call the function to draw a line
    // Call the function to draw the 'X' pattern
    draw_x();
    draw_line(); // Call the function to draw another line
    draw_xx(); // Call the function to draw another 'X' pattern


    // Return 0 to indicate successful execution
    return 0;
}


// This program prints a right-angled triangle pattern of asterisks.
// The outer loop controls the number of rows, while the inner loop controls the number of asterisks printed in each row.
// The pattern will look like this:
// *
// **
// ***
// ****
// *****
// ******
// *******
// ********
void print_triangle_pattern() {
    int i, j;
    for (i = 1; i < 9; i++) {
        for (j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}
// This program prints a pattern of 'X' using asterisks.
void draw_x()
{
    int i,j;
    for (i=0;i<50;i++)
    {
        for (j=0;j<50;j++)
        {
            if (i==j)
            {
                printf("*");
            }
            if (i==50-j)
            {
                printf("*");
            }
            printf(" ");
        }
        printf("\n");

    }
}

void draw_line()
{
    printf("--------------------------------------------------\n");
}

void draw_xx()
{
    unsigned int i;
    unsigned int j;
    unsigned int a=20;

   for(i  = 0; i < a; i++)
{
   for(j = 0; j < a; j++)
   {
     if( i == j)
        printf("*");
     else if( i == ( a - j ) )
        printf("*");
     else
        printf(" ");

   }
  printf("\n");
}
}