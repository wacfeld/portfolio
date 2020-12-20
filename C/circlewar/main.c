#include <stdio.h>
#include <stdlib.h>

#define INSERT_RANDOM 1 // as opposed to the bottom of the deck
#define SUIT_SIZE 13
#define START_SUITS 1

int max_deck = SUIT_SIZE * START_SUITS * 2q;

int deck0[max_deck];
int deck1[max_deck];

int 
int b0 = 0, b1 = 0, e0 = 0, e1 = 0;

int getnext(int deck[], int * b)
{
    int x = deck[*b];
    ++(*b);
    *b %= max_deck;
    return x;
}

void pushlast(int deck[], int * e, int val)
{
    deck[*e] = val;
    ++(*e);
    *e %= max_deck;
}

int compare(int n1, int n2)
{
    // two chases one
    float dist = (n2 - n1) % SUIT_SIZE;
    if(dist == 0 or dist == 
}

int main()
{
    for(int i = 0; i < SUIT_SIZE; ++i)
    {
        for(int j = 0; j < START_SUITS * 2; ++j)
        {
            if(rand() % 2 == 0) deck0[e0++] = i;
            else deck1[e1++] = i;
        }
    }

    
    
}
