#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    //checking if is only 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    // checkign if all the content is only digits
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }
    //converting argv[1] to an integer
    int n = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    //checking each character in the text.
    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        //do this is its upper
        if (isupper(plaintext[i]) && isalpha(plaintext[i]))
        {
            printf("%c", ((((plaintext[i] - 65 + n)) % 26)) + 65);
        }
        //do this if is lower
        else if (islower(plaintext[i]) && isalpha(plaintext[i]))
        {
            printf("%c", ((((plaintext[i] - 97 + n)) % 26)) + 97);
        }
        //print the character if its not alpha
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}


