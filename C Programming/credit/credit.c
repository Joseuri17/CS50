#include <cs50.h>
#include <stdio.h>
int z;
int x;
int y = 0;
int doublesum = 0;
long n;
int main(void)
{
    n = get_long("enter card number: ");
    //checks less than 13 digits or greater than 16 digits
    long test = n;
    long rest = n;

    //adding the 2nd to last digits
    while (test > 0)
    {
        long last_num = test / 10;
        long everyother = last_num % 10;
        x = everyother * 2;
        // seperating double digits.
        if (x >= 10)
        {
            x = x % 10;
            x++;
        }
        doublesum = doublesum + x;
        test = test / 100;
    //printf("every other is: %li, %i \n", everyother, x);
    //printf("double sum is: %i \n", doublesum);
    }
    // adding the last digits together NOT counted
    while (rest > 0)
    {
        long last = rest % 10;
        y = y + last;
        rest = rest / 100;
        // printf ("rest of numbers is: %i \n", y);
    }
    z = doublesum + y;
    // printf("%i", z);

    if (z % 10 != 0 || n < 999999999999)
    {
        printf("INVALID\n");
    }
    else if (z % 10 == 0 && n > 999999999999)
    {
        // checking if its 13 or 16 digits and starts with 4
        if ((n > 999999999999 && n < 10000000000000 && n / 1000000000000 == 4) || (n > 999999999999999 && n < 10000000000000000 && n / 1000000000000000 == 4))
        {
            printf("VISA\n");
        }
        //checking if is 16 digits
        else if ((n > 999999999999999 && n < 10000000000000000) && (n / 100000000000000 == 51 || n / 100000000000000 == 52 || n / 100000000000000 == 53 || n / 100000000000000 == 54 || n / 100000000000000 == 55))
        //checking if it starts with either 52,52,53,54,55
        {
            printf("MASTERCARD\n");
        }
        //checking if its 15 digits
        else if ((n > 99999999999999 && n < 1000000000000000) && (n / 10000000000000 == 34 || n / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}