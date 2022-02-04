#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many test? ");
    int sum = 0;
    int scores[n];

    for(int i = 0; i < n; i++)
    {
        scores[i] = get_int("Scores: ");
    }

    for(int j = 0; j <= n; j++)
    {
        sum += scores[j];
    }
    int avg = sum / n;
    printf("Average: %i\n", avg);
}