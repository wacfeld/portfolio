#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//int pegs[15];
//int lines[][5] = {{0, 1, 3, 6, 10}, {2, 4, 7, 11}
/*typedef struct node {
	int val;
	// tl, tr, l, r, bl, br
	// 0,  1,  2, 3, 4,  5
	
	struct node *tl;
	struct node *tr;
	struct node *l;
	struct node *r;
	struct node *bl;
	struct node *br;
} node;*/
int done[100000][30];
int dc = 0;
int duplicate = 0;
void pmoves(int moves[30])
{
    if(dc != 0)
    {
        for(int i = 0; i < dc; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                if(done[i][j] != moves[j])
                {
                    goto ffff;
                }
            }
        }
        puts("found a tduplitace!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        duplicate++;
            return;
    }
ffff:
	for(int i = 0; i < 15; i++)
    {
        printf("%02d %02d  ", moves[2*i], moves[2*i+1]);
        
    }
    for(int i = 0; i < 30; i++)
    {
        done[dc][i] = moves[i];
    }
    dc++;
	puts("");
}
void plist(int list[15][7])
{
	printf("    %d\n   %d %d\n  %d %d %d\n %d %d %d %d\n%d %d %d %d %d\n\n", list[0][0],list[1][0],list[2][0],list[3][0],list[4][0],list[5][0],list[6][0],list[7][0],list[8][0],list[9][0],list[10][0],list[11][0],list[12][0],list[13][0],list[14][0]);
	


}
int list[15][7] = {{1, -1, -1, -1, -1, 1, 2},
	{1, -1, 0, -1, 2, 3, 4},
	{1, 0, -1, 1 , -1, 4, 5},
	{1,-1, 1, -1, 4, 6, 7},
	{1, 1, 2, 3, 5, 7, 8},
	{1, 2, -1, 4, -1, 8, 9},
	{1, -1, 3, -1, 7, 10, 11},
	{1, 3, 4, 6, 8, 11, 12},
	{1, 4, 5, 7, 9, 12, 13},
	{1, 5, -1, 8, -1, 13, 14},
	{1, -1, 6, -1, 11, -1, -1},
	 {1, 6, 7, 10, 12, -1, -1},
	{1, 7, 8, 11, 13, -1, -1},
	 {1, 8, 9, 12, 14, -1, -1},
	 {0, 9, -1, 13, -1, -1, -1}};
int lowest = 15;
int failed = 0;
void get(int moves[30], int c, int l[15][7], int nleft)
{
	//int (*cur)[7];
	//int (*adj)[7];
    int recursed = 0;
	for(int i = 0; i < 15; i++)
	{
		//cur = l+i;
		if(l[i][0] == 0) continue;
		for(int j = 1; j < 7; j++)
		{
			//adj = l + cur[j];
			if(l[i][j] != -1 && l[l[i][j]][0] == 1 && l[l[i][j]][j] != -1 && l[l[l[i][j]][j]][0] == 0)
			{
				int (*p)[7] = malloc(7*15*sizeof(int));
				memcpy(p,l,7*15*sizeof(int));

				p[i][0] = 0;
				p[p[p[i][j]][j]][0] = 1;
				p[p[i][j]][0] = 0;
				nleft;
				moves[c] = i;
				moves[c+1] = p[p[i][j]][j];
				
                recursed = 1;
				if(nleft == 3)
				{
					pmoves(moves);
					
					return;
                }
				
				get(moves,c+2,p,nleft-1);
			}
		}
	}
    if(!recursed)
    {
        failed ++;
    }
}

int main()
{
	
	int moves[30];
	for(int i= 0; i < 30; i++) moves[i] = -1;
	int (*copy)[7] = malloc(7* 15 * sizeof(int));
	memcpy(copy,list,7*15*sizeof(int));
	get(moves, 0, copy, 15);
    printf("success: %d\nfail: %d\n",dc, failed);
    printf("duplicates: %d\n",duplicate);
	
}
