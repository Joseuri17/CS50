#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

//Number of voters
int voter_count;

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool check_cycle(int a, int b);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }

    }
return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            // this is a 2d array.
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            //if more voted prefered i over canidate j set i as winner and j as loser
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            //if more voted prefered j over canidate i set j as winner and i as loser.
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[i].winner][pairs[i].loser] < preferences[pairs[j].winner][pairs[j].loser])
            {
                // selection sorting.
                pair n = pairs[i];
                pairs[i] = pairs[j];
                pairs[j] = n;
            }
        }
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // if the loser beats anybody that are already locked check if it creates a cycle.
            if (locked[pairs[i].loser][j])
            {
                locked[pairs[i].winner][pairs[i].loser] = check_cycle(pairs[i].winner,pairs[i].loser);
                break;
            }
            else if (j == candidate_count - 1)
            {
                // set locked to true winner locked over loser.
                locked[pairs[i].winner][pairs[i].loser] = true;
            }
        }
    }
    return;
}
bool check_cycle(int a, int b)
{
    // set 1 to b(loser) and 3 to a(winner).
    if (a == b)
    {
        return false;
    }
    // loop through the graph. (pairs con
    for (int i = 0; i < candidate_count; i++)
    {
        // if there it a T in the graph of b x axis.
        if (locked[b][i])
        {
            //repeat / if the next cycle is returning false then the cycle is not true and it wont keep going
            // else if the loser never wins over someone the nreturn true;
            //if the loop ever returns false then there is a loop and the function base check cycle. returns false.
            if (check_cycle(a, i) == false)
                return false;
        }
    }
    return true;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    //go through each row
    for (int i = 0; i < candidate_count; i++)
    {
        //go through each column
        for (int j = 0; j < candidate_count; j++)
        {
            // flip the j and i backwards like y, x. column (i) then row (j) and search for true in a graph.
            if (locked[j][i] == true)
            {
                break;
            }
            // if it finished looping through the last cadidate and its false print the winner on column (i). that person is not beaten by anybody.
            else if (locked[j][i] == false && j == candidate_count - 1)
            {
                printf("%s\n", candidates[i]);
            }
        }
    }
    return;
}