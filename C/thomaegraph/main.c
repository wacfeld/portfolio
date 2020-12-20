#include <stdio.h>
#include <stdlib.h>

#define DENOM 100
#define MIN 0 // inclusive
#define MAX 1

int gcd(int p, int q)
{
    if(p == 0) return 0;
    int rem;
    while((rem = p % q) != 0)
    {
        p = q;
        q = rem;
    }
    return q;
}

int* reduce(int p, int q)
{
    int* res = (int*) malloc(sizeof(int) * 2);
    int g = gcd(p, q);
    if(g == 0)
    {
        res[0] = 0;
        res[1] = 0;
        return res;
    }
    res[0] = (int) p/g;
    res[1] = (int) q/g;
    return res;
}
int main()
{
    double ex[(int)(DENOM * (MAX - MIN) + 2)];
    double why[(int) (DENOM * (MAX - MIN) + 2)];

    int i = 0;
    double x = MIN;
    for(; x <= MAX; (i++, x = MIN + (double) i / DENOM))
    {
        int * res = reduce(i, DENOM);
        ex[i] = x;
        if(res[0] == 0 && res[1] == 0) why[i] = 0.0;
        else why[i] = res[1];
        printf("%f %f\n", x, why[i]);
    }
    printf("out\n");
    return 0;
}
