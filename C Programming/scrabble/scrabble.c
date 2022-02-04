#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1,3,3,2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int pos = 0;
    int value = 0;
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //go here if its uppsercase
        if (isupper(word[i]))
        {
            // gets the value of the letter position
            value = (word[i] - 65);
            // display the POINT value bcs of the position
            pos = POINTS[value];
            //adds it to the score.
            score += pos;
        }
        //go here if its lowercase
        else if (islower(word[i]))
        {
            value = (word[i] - 97);
            pos = POINTS[value];
            score += pos;
        }
    }
    return score;
}
