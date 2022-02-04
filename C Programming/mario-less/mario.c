#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: \n");
    }
    while (n < 1 || n > 8);


// for each row
    for (int i = 0 ; i  < n; i++)
    {
// for each column
        for (int j = 0; j < n; j++)
        {
            if (j < n - 1 - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
//add a new line
        printf("\n");
    }
}



