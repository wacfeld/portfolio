#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define min(i,j) (i<j ? i : j)
#define swap(arr,i,j) {int temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;}
#define putd(a) printf(#a " = %d", a)
#define putf(a) printf(#a " = %f", a)

void bub_sort(int arr[], int n)
{
    for(int i = n; i > 0; i--)
    {
        for(int j = 0; j < i-1; j++)
        {
            if(arr[j] < arr[j+1])
                swap(arr,j,j+1);
        }
    }
}

int *outcome(int a, int d) // outputs the number of troops att and def leave with, 0 = loss for that side
{
    int *res = malloc(sizeof(int) * 2);
    if(a == 0 || d == 0)
    {
        res[0] = a, res[1] = d;
        return res;
    }

    int mina = min(a,3);
    int mind = min(d,2);
    int att[mina], def[mind];

    for(int i = 0; i < mina; i++)
        att[i] = rand() % 6;
    for(int i = 0; i < mind; i++)
        def[i] = rand() % 6;

    bub_sort(att,mina);
    bub_sort(def,mind);
    int minad = min(a,d);
    for(int i = 0; i < minad; i++)
    {
        if(att[i] > def[i])
            d--;
        else
            a--;
    }
    return outcome(a,d);
}

int main()
{
    time_t t;
    srand((unsigned) time(&t));

    enum mode {PER, RES};// which data to output, percentage won, or average aftermath
    enum mode m;
    puts("per/res (p/r)? ");
    char c = getchar();
    m = c=='p' ? PER : RES;

    double samp_size = 100000.0;
    int max_size = 15;

    for(int i = 1; i <= max_size; i++)
        printf("\t%d",i);
    putchar('\n');
    for(int a = 1; a <=max_size; a++)
    {
        double aline[(int)max_size];
        double dline[(int)max_size];
        for(int d = 1; d <= max_size; d++)
        {
            int res[2] = {};
            int awin = 0, dwin = 0;
            for(int i = 0; i < (int) samp_size; i++)
            {
                int *out = outcome(a,d);
                res[0] += out[0];
                res[1] += out[1];

                if(out[0] == 0 && out[1] != 0)
                    dwin++;
                else if(out[0] != 0 && out[1] == 0)
                    awin++;

                free(out);
            }
            
            if(m == PER)
            {
                aline[d-1] = 100*awin/samp_size;
                dline[d-1] = 100*dwin/samp_size;
            }
            else
            {
                aline[d-1] = res[0]/samp_size;
                dline[d-1] = res[1]/samp_size;
            }
        }

        printf("%d",a);
        //for(int i = 0; i < max_size; i++)
        //    printf("\t%3.1f", dline[i]);
        //putchar('\n');
        for(int i = 0; i < max_size; i++)
            printf("\t%3.1f", aline[i]);
        printf("\n");
    }

    return 0;
}
