#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define putd(x) printf(#x ": %d\n", x)

#define DICTLEN 97

typedef struct node
{
    char name[100];
    int age;
    struct node *next;
} node;

node dict[DICTLEN];

int hash(char name[100], int len)
{
    long prod = 1;
    for(int i = 0; i < 5 && i < len; i++)
    {
        prod *= tolower(name[i])-'a'+1;
    }
    return prod % DICTLEN;
}

int lenlink(node *n)
{
    if(n->age == -1)
    {
        return 0;
    }
    int i = 0;
    while(i++,(n = n->next) != NULL);
    return i;

}
int main()
{
    for(int i = 0; i < DICTLEN; i++)
    {
        dict[i].next = NULL;
        dict[i].age=-1;
    }

    char name[100];
    int age;
    while(scanf("%s %d", name, &age) != EOF)
    {
        int h = hash(name, strlen(name));
        node *n = dict+h;
        node *new = (node *) malloc(sizeof(node));
        strcpy(new->name,name);
        new->age = age;
        if(n->age==-1)
        {
            *n = *new;
        }
        else
        {
            while((n->next) != NULL) n = n->next;
            n->next = new;
        }
    }
    
    int sum = 0;
    for(int i = 0; i < DICTLEN; i++)
    {
        //putd(lenlink(dict+i));
        printf("%d\n",lenlink(dict+i));
        sum += lenlink(dict+i);

    }
    putd(sum);

}
