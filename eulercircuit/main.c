#include <stdio.h>
//#include <assert.h>
//#include <ctype.h>
//#include <errno.h>
//#include <float.h>
//#include <limits.h>
//#include <locale.h>
//#include <math.h>
//#include <setjmp.h>
//#include <signal.h>
//#include <stdarg.h>
//#include <stddef.h>
#include <stdlib.h>
//#include <string.h>
//#include <time.h>
#define putd(x) printf(#x ": %d\n", x)
#define MAXADJ 100
#define MAXVERT 100

typedef struct vert
{
    char name;
    int numadj;
    struct vert *adj[MAXADJ];
} vert;

void addedge(vert *v1, vert *v2)
{
    for(int i = 0; i < MAXADJ; i++)
        if(!v1->adj[i])
        {
            v1->adj[i] = v2;
            v1->numadj++;
            break;
        }
    for(int i = 0; i < MAXADJ; i++)
        if(!v2->adj[i])
        {
            v2->adj[i] = v1;
            v2->numadj++;
            break;
        }
}

void deledge(vert *v1, vert *v2)
{
    int i;
    for(i = 0; i < MAXADJ; i++)
        if(v1->adj[i] == v2)
        {
            v1->adj[i] = 0;
            v1->numadj--;
            break;
        }
    for(i = 0; i < MAXADJ; i++)
        if(v2->adj[i] == v1)
        {
            v2->adj[i] = 0;
            v2->numadj--;
            break;
        }
}

vert *firstedge(vert *v)
{
    for(int i = 0; i < MAXADJ; i++)
    {
        if(v->adj[i])
            return v->adj[i];
    }
    return 0;
}

vert **closedpath(vert *r)
{
    vert *v = r;
    vert **path = malloc(sizeof(vert *) * MAXVERT);
    int p = 0;
    path[p++] = r;

    vert *t;

    do
    {
        if((t = firstedge(v)))
        {
            deledge(v,t);
            v = t;
            path[p++] = v;
        }
        else
        {
            return 0;
        }
    } while(r != v);

    path[p] = 0;
    return path;
}

void circuit(vert *r)
{
    vert **path = closedpath(r);
    int exp = 0;
    for(vert **c = path; *c; c++)
    {
        if(!exp && (*c)->numadj)
        {
            circuit(*c);
            exp = 1;
        }
        else
        {
            putchar((*c)->name);
        }
    }
}

int main()
{
    vert v[5] = {{'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}};
    addedge(v, v+1);
    addedge(v, v+3);
    addedge(v+1, v+2);
    addedge(v+1, v+2);
    addedge(v+1, v+3);
    addedge(v+2, v+3);
    addedge(v+2, v+4);
    addedge(v+3, v+4);
    circuit(v);
}
