#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{

string word = get_string("Text: ");

    for (int i = strlen(word), n = 0; i >= n; i--)
    {

        printf("%c", word[i]);

    }
        printf("\n");

}