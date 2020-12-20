#include "concepts.h"

byte *shl(word w, int n)
{
    byte *copy = (byte *) malloc(U);
    for(int i = 0; i < W-n; i++)
        copy[i] = w[i+n];
    return copy;
}

byte *shr(word w, int n)
{
    byte *copy = (byte *) malloc(U);
    for(int i = W-1; i >= n; i--)
        copy[i] = w[i-n];
    return copy;
}

byte *or(word w, word x)
{
    byte *copy = (byte *) malloc(U);
    for(int i = 0; i < W; i++)
        copy[i] = w[i] || x[i];
    return copy;
}

byte *xor(word w, word x)
{
    byte *copy = (byte *) malloc(U);
    for(int i = 0; i < W; i++)
        copy[i] = w[i] ^ x[i];
    return copy;
}

byte *rotl(word w, int n)
{
    return or(shl(w, n), shr(w, W-n));
}

void zero(word w)
{
    for(int i = 0; i < W; i++)
        w[i] = 0;
}

byte *add(word w, word x)
{
    byte *copy = (byte *) malloc(U);
    for(int i = 0; i < W, i++)
        copy[i] = w[i] + x[i];
    return copy;
}
    
