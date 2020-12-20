// not used in this project, just a reference

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

// locations
#define GO 0
#define JAIL 10
#define GOJAIL 30 // gotojail spot
#define ELECT 12
#define WATER 28

#define NUM_ROUNDS 100000000
#define SHUF_SWAPS 1000
#define NUM_PLAY 1

#define REL 0 // relative direction
#define ABS 1 // absolute location
#define NEX 2 // next of some type
#define FOR 3 // end turn, go to jail

#define size(a) ((sizeof a)/(sizeof a[0])) // doesn't work in function since decay to ptr

// for NEX cards
#define RAIL 0
#define UTIL 1

long freq[40]; // default init to 0
int spec[] = {2, 7, 17, 22, 30, 33, 36}; // comm chest, chance, gotojail spots
int comm_s[] = {2, 17, 33}; // s = spots
int chan_s[] = {7, 22, 36};
int comm[][2] = {[0 ... 13] = {REL,0}, {ABS,0}, {FOR,10}}; // nothing, GO, JAIL
int chan[][2] = {[0 ... 5] = {REL,0}, {REL, -3}, {FOR, 10}, {ABS, 0}, {ABS, 5}, {ABS, 39}, {ABS, 11}, {ABS, 24},
    {NEX, RAIL}, {NEX, RAIL}, {NEX, UTIL}}; // chance cards suck in both playing and implementation

// top of deck
int comm_i = 0;
int chan_i = 0;

int in(int p, int spots[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(p == spots[i])
            return 1;
    }
    return 0;
}

int roll_two(int *res) // sum 2 dice rolls, return "1" if same
{
    int r1 = rand() % 6 + 1;
    int r2 = rand() % 6 + 1;
    *res = r1 + r2;
    if(r1 == r2)
        return 1;
    return 0;
}

int *draw_comm() // assume deck already shuffled
{
    int *card = comm[comm_i++];
    comm_i %= size(comm);
    return card;
}
int *draw_chan()
{
    int *card = chan[chan_i++];
    chan_i %= size(chan);
    return card;
}

int turn(int p)
{
    int dbl_cnt = 0;
    int res;
    int dbl;
    do // rolling
    {
        if((dbl = roll_two(&res))) // double
            if(++dbl_cnt == 3) // record, go to jail
            {
                freq[JAIL]++;
                return JAIL;
            }

        int newp = -1; // -1 = ignore, otherwise set p to this
        do // obeying movement commands
        {
            if(newp >= 0) // then obey it
            {
                p = newp;
                newp = -1;
            }
            else
                p = (p+res + 40) % 40; // extra 40 because C rounds negatives badly
            freq[p]++; // record

            if(in(p, spec, size(spec)))
            {
                int *card;

                if(in(p, comm_s, size(comm_s)))
                    card = draw_comm();
                else if(in(p, chan_s, size(chan_s)))
                    card = draw_chan();
                else if(p == GOJAIL)
                {
                    freq[JAIL]++;
                    return JAIL;
                }

                if(card[0] == REL)
                    res = card[1];
                else if(card[0] == ABS)
                {
                    newp = card[1];
                } else if(card[0] == NEX)
                {
                    if(card[1] == RAIL) // round to tens, then add 5
                    {
                        newp = round(p/10.0)*10 + 5;
                        newp %= 40;
                    } else if(card[1] == UTIL) // check with inequalities
                    {
                        if(ELECT <= p && p < WATER) // go to water
                            newp = WATER;
                        else // go to electricity
                            newp = ELECT;
                    }
                } else if(card[0] == FOR)
                {
                    freq[JAIL]++;
                    return JAIL;
                }

                if(newp == -1 && res == 0)
                    break;
            }
        } while(in(p, spec, size(spec))); // looking at old value of p
    } while(dbl);

    return p;
}

void copy_2(int *from, int *to) // assuming size 2
{
    to[0] = from[0];
    to[1] = from[1];
}
void shuffle(int deck[][2], int n)
{
    for(int i = 0; i < SHUF_SWAPS; i++)
    {
        int r1 = rand() % n;
        int r2 = rand() % n;
        int t[2];
        copy_2(deck[r1],t);
        copy_2(deck[r2],deck[r1]);
        copy_2(t,deck[r2]);
    }
}

int main()
{
    srand(time(NULL));
    
    shuffle(comm, size(comm));
    shuffle(chan, size(chan));

    int players[NUM_PLAY]; // rep. their positions
    for(int i = 0; i < NUM_PLAY; i++)
        players[i] = GO;

    for(int i = 0; i < NUM_ROUNDS; i++)
    {
        for(int j = 0; j < NUM_PLAY; j++)
        {
            players[j] = turn(players[j]);
        }
    }

    for(int i = 0; i < 40; i++)
    {
        printf("%lu\n", freq[i]);
    }


}
