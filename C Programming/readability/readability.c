#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int count_letters(string text);
int count_words(string text);
int count_sentence(string text);

int main(void)
{
    int index = 0;
    float L = 0;
    float S = 0;


    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentence(text);

    //Average of Letters
    L = (float)letters / words * 100;
    //Average of Sentences
    S = (float) sentences / words * 100;
    // calculating the formula of Coleman-liau
    index = round((float) 0.0588 * L - 0.296 * S - 15.8);

    //comparing values.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}


//counting my letters
int count_letters(string text)
{
    int l = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            l++;
        }
    }
    return l;
}

//counting my words
int count_words(string text)
{
    int w = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            w++;
        }
    }
    return w;
}
//counting the number of sentences
int count_sentence(string text)
{
    int s = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++;
        }
    }
    return s;
}