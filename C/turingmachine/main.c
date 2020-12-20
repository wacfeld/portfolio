#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BLOCKSIZE 5


// N_* always at end, let C auto-assign enum values; preserve BLANK at beginning (0) and HALT whereever
typedef enum symbols {BLANK, ON, N_SYMB} symb;
typedef enum states {A, B, C, HALT, N_STATE} state;

symb *tape;
int curmax = BLOCKSIZE;
int head = BLOCKSIZE/2;
state curstate = 0;

void exp_tape();
void iterate();
void printtape();

int table[N_STATE][N_SYMB][3] = { // 3: replacement symbol, head movement, new state
    {{ON, 1, B}, {ON, -1, C}},
    {{ON, -1, A}, {ON, 1, B}},
    {{ON, -1, B}, {ON, 1, HALT}}
};

void exp_tape(int left)
{
    tape = (symb *)realloc(tape, (curmax + BLOCKSIZE) * sizeof(symb));
    memset(tape + curmax, 0, BLOCKSIZE * sizeof(symb));

    if(left)
    {
        memmove(tape + BLOCKSIZE, tape, curmax * sizeof(symb));
        head += BLOCKSIZE;
        memset(tape, 0, BLOCKSIZE * sizeof(symb));

    }
    // if right, nothing special
    curmax += BLOCKSIZE;
}

void iterate()
{
    symb cursymbol = tape[head];
    int *comm = table[curstate][cursymbol];
    tape[head] = comm[0];
    head -= comm[1];
    curstate = comm[2];
}

void printtape()
{
    int nchars = 0;
    int ncur;
    for(int i = 0; i < curmax; i++)
    {
        printf(" %4d%n", tape[i], &ncur);
        if(i <= head)
            nchars += ncur;
    }
    printf("%10d\n", curstate);
    for(int i = 0; i < nchars-1; i++)
    {
        printf(" ");
    }
    puts("^");
}

int main()
{
    tape = (symb *)calloc(BLOCKSIZE, sizeof(symb)); // calloc -> 0 -> BLANK
    printtape();
    while(curstate != HALT)
    {
        iterate();
        if(head < 0)
            exp_tape(1); // expand left
        else if(head >= curmax)
            exp_tape(0); // expand right
        printtape();
    }
}
