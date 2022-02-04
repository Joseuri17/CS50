#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input:  ");
    printf("After: ");

    for(int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i] - 1));
    }
    printf("\n");
}
