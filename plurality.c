#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Max Canidates
#define MAX 9


//Structure called canidate that stores a string and int
typedef struct
{
    string name;
    int votes;
}
canidate;

// Array of canidates called canidates
canidate canidates[MAX];

int canidate_count;

// Function prototypes
bool vote (string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Make sure no. of arguments are more than 2
    if (argc < 3)
    {
        printf("Usage: ./plurality [Canidates....]\n");
        return 1;
    }
    // Gets no. of canidates
    canidate_count = argc - 1;
    if (canidate_count > 9)
    {
        printf("Max of 9 canidates allowed.\n");
        return 1;
    }
    // Assigning canidates to canidates array
    // Initalizing votes to 0
    for (int i = 0; i < canidate_count; i++)
    {
        canidates[i].name = argv[i + 1];
        canidates[i].votes = 0;
    }
    // Getting number of voters
    int voter_count = get_int("Number of voters: ");

    // Confirms vote is valid
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("Invalid vote\n");
        }
    }
    print_winner();
}

bool vote (string name)
{
    // Compares vote to canidates
    for (int i = 0; i < canidate_count; i++)
    {
        if (strcmp(name, canidates[i].name) == 0)
        {
            canidates[i].votes++;
            return 0;
        }
    }
    return 1;
}

void print_winner(void)
{
    int most_votes = 0;

    //finds the canidate with most votes
    for (int i = 0; i < canidate_count; i++)
    {
        if (canidates[i].votes > most_votes)
        {
            most_votes = canidates[i].votes;
        }
    }
    // Prints canidate with most votes
    for (int i = 0; i < canidate_count; i++)
    {
        if (canidates[i].votes == most_votes)
        {
            printf("%s\n", canidates[i].name);
        }
    }
}
