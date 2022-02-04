// Implements a dictionary's functionality
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>
#include <string.h>
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26*26*26 + 701;
//seting node to global variable.
node *n = NULL;
// Hash table
node *table[N];

//creating a global variable counting the words.
int totalwords = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    //TODO
    //gettin the hash code.
    int index = hash(word);
    // using the hash code to irrerate thru the hash table.
    node *cursor = table[index];
    //use strcasecmp. has the word. access the linked list at the index.
    while(cursor != NULL)
    {
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }

    }
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int len = strlen(word);
    int x = 0;

    if (len > 2)
    {
        x += 26 * 26 * (1 + toupper(word[0]) - 'A');
        x += 26 * (1 + toupper(word[1]) - 'A');
        x += toupper(word[2]) - 'A';
    }

    else if(len > 1)
    {
        x +=26 * (1 + toupper(word[0]) - 'A');
        x += toupper(word[1]) - 'A';
    }

    else if(len > 0)
    {
        x = toupper(word[0]) - 'A';
    }
    return x;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //create the size of string to fit in the array.
    char *w = malloc(sizeof(char) * LENGTH + 1);
    //checkign if null.
    if (w == NULL)
    {
        free(w);
        return false;
    }

    // TODO
    FILE *file = fopen(dictionary, "r");
    if(file == NULL)
    {
        printf("could not open dictionary");
        fclose(file);
        return false;
    }

    while(fscanf(file, "%s", w) != EOF)
    {
        totalwords++;
        int index = hash(w);
        //creating a new node that is going to store a word in my hash table.
        n = malloc(sizeof(node));
        //check if null
        if (n == NULL)
        {
            free(n);
            return false;
        }
        strcpy(n->word, w);
        n->next = NULL;
        //array hash table is empty copy word into that node using strcpy.
        if(table[index] == NULL)
        {
            table[index] = n;
        }
        //if is [index] is not null need to replace new to head and head to the new.
        else
        {
            n->next = table[index];
            table[index] = n;
        }

    }
    free(w);
    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return totalwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor = NULL;
    node *tmp = NULL;
    for (int i = 0; i <= N; i++)
    {
        cursor = table[i];
        tmp = cursor;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
