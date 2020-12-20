#include <stdio.h>
#include <stdlib.h>

int taken[][2] =
{
    0, 0,

    2, 0,
    3, 0,
    4, 0,
    5, 0,
    6, 0,
    7, 0,
    
    0, 1,
    1, 1,
    2, 1,
    3, 1,
    4, 1,
    5, 1,
    6, 1,
    7, 1,
    
    0, 6,
    1, 6,
    2, 6,
    3, 6,
    4, 6,
    5, 6,
    6, 6,
    7, 6,

    0, 7,
    1, 7,
    2, 7,

    4, 7,
    5, 7,
    6, 7,
    7, 7,
};

int in_board(int loc[])
{
    if(0 <= loc[0] && loc[0] < 7 && 0 <= loc[1] && loc[1] <= 7)
        return 1;
    return 0;
}

int overlap(int loc[], int taken[][2], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(loc[0] == taken[i][0] && loc[1] == taken[i][1])
            return 1;
    }
    return 0;
}

void knight_moves(int loc[], int moves[8][2]) // does not check for legality
{
    int x = loc[0];
    int y = loc[1];
    int temp[8][2] = 
    {
        {x-2, y-1,},
        {x-2, y+1,},
        {x+2, y-1,},
        {x+2, y+1,},
        {x-1, y-2,},
        {x+1, y-2,},
        {x-1, y+2,},
        {x+1, y+2,},
    };
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 2; j++)
            moves[i][j] = temp[i][j];
    }
}

int success[20] = {};
void search(int loc[], int dest[], int turn)
{
    if(turn > 11)
        return;
    int moves[8][2];
    knight_moves(loc, moves);
   /* 
printf("%d: %d %d\n", turn, loc[0], loc[1]);
for(int i = 0; i < 8; i++)
    printf("%d %d\n", moves[i][0], moves[i][1]);
printf("\n\n\n");
*/


    for(int i = 0; i < 8; i++)
    {
        int *mov = moves[i];
        if(overlap(mov, taken, sizeof(taken)/sizeof(taken[0])) || !in_board(loc))
            continue;
        if(mov[0] == dest[0] && mov[1] == dest[1])
        {
            success[turn]++;
        }
        search(mov, dest, turn+1);
    }
}

int main()
{
    int loc[] = {1,0};
    int dest[] = {3,7};
    search(loc, dest, 1);
    for(int i = 0; i < sizeof(success)/sizeof(success[0]); i++)
        printf("%d: %d\n", i, success[i]);
}
