#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLEN 1000
#define VOWEL(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')

void lower(char *s)
{
    for(;*s != '\0'; ++s)
    {
        *s = tolower(*s);
    }
}
void nopunc(char *p)
{
    char *q = p;
    for(;*p != '\0'; ++p)
    {
        if(isalnum(*p))
            *(q++) = *p;
        
    }
    *q = '\0';
}

int letcmp(char *a, char *b) // letter compare; vowels come first, excluding y
{
    if(VOWEL(*a))
    {
        if(VOWEL(*b))
        {
            return strcmp(a,b);
        }
        return -1;
    }
    if(VOWEL(*b))
    {
        return 1;
    }
    return strcmp(a,b);
}

int main(int argc, char *argv[])
{ 
    char s[MAXLEN];
    fgets(s,MAXLEN,stdin);
    
    lower(s);
    nopunc(s);

    qsort(s, strlen(s),sizeof(char),(int (*)(const void*, const void*))letcmp); 

    printf("%s\n", s);
    return 0; 
} 
