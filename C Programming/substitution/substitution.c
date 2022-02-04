#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    int new = 0;
//checking for input
    if (argc != 2)
    {
        printf("USAGE: ./subtitution key \n");
        return 1;
    }
    //checking to see if its 26 char long.
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]))
        {
            printf("Key must only contsain alphabetic characters.\n");
            return 1;
        }
        // check if the length is 26 char long
        else if (strlen(argv[1]) != 26)
        {
            printf("Key must contsain 26 characters.\n");
            return 1;
        }
        // Loop through index starting in j[1] for J to check if there is repitition
        for (int j = i + 1, o = strlen(argv[1]); j < o; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    //get input from the user.
    string ptext = get_string("Plaintext: ");
    printf("ciphertext: ");
    // replace char by the array of argv[]
    for (int k = 0, len = strlen(ptext); k < len; k++)
    {
        // do this if its a uppercase letter
        if (isupper(ptext[k]))
        {
            // setting the index value subtracting A and printing that indext with argv
            new = ptext[k] - 'A';
            printf("%c", toupper(argv[1][new]));
        }
        else if (islower(ptext[k]))
        {
            //// setting the index value subtracting a and printing that indext with argv
            new = ptext[k] - 'a';
            printf("%c", tolower(argv[1][new]));
        }
        // Printing nums or char as is.
        else
        {
            printf("%c", ptext[k]);
        }

    }

    printf("\n");

}
