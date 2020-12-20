#include "concepts.h"

#define P64 ((word) 0xB7E151628AED2A6B)
#define P32 ((word) 0xB7E15163)
#define P16 ((word) 0xB7E1)
#define Q64 ((word) 0x9E3779B97F4A7C15)
#define Q32 ((word) 0x9E3779B9)
#define Q16 ((word) 0x9E37)

word get_p()
{
    if(W == 64)
        return P64;
    else if(W == 32)
        return P32;
    else if(W == 16)
        return P16;
    perror("get_p: bad word size");
    exit(1);
}

word get_q()
{
    if(W == 64)
        return Q64;
    else if(W == 32)
        return Q32;
    else if(W == 16)
        return Q16;
    perror("get_q: bad word size");
    exit(1);
}

word rotl(word d, int n)
{
    return (d << n) | (d >> (W-n));
}

word rotr(word d, int n)
{
    return (d >> n) | (d << (W-n));
}

word *key_expand(byte *K)
{
    int i, j, k;
    word Ay;
    word Be;
 

    word *L = (word *) calloc(C, sizeof(word)); // allocate L[C] of words, cleared to zero
    for(i = B-1; i >= 0; i--)
        L[i/U] = rotl(L[i/U], 8) + K[i];

    word *S = (word *) malloc(sizeof(word)  * T);
    S[0] = get_p();
    for(i = 1; i < T; i++)
        S[i] = S[i-1] + get_q();

    i = j = 0;
    Ay = Be = 0;
    for(k = 0; k < 3*MAX(T,C); k++)
    {
        Ay = S[i] = rotl(S[i] + Ay + Be,3);
        Be = L[j] = rotl(L[j] + Ay + Be, Ay+Be);
        i = (i + 1) % T;
        j = (j + 1) % C;
    }
    
    return S;
}

word *encrypt_blocks(word Ay, word Be, word *S)
{
    Ay += S[0];
    Be += S[1];
    
    int i;
    for(i = 1; i <= R; i++)
    {
        Ay = rotl(Ay ^ Be, Be) + S[2 * i];
        Be = rotl(Be ^ Ay, Ay) + S[2 * i + 1];
    }

    word * res = (word *) malloc(sizeof(word) * 2);
    res[0] = Ay;
    res[1] = Be;
    return res;
}

word *decrypt_blocks(word Ay, word Be, word *S)
{
    for(int i = R; i >= 1; i--)
    {
        Be = rotr(Be - S[2*i + 1], Ay) ^ Ay;
        Ay = rotr(Ay - S[2*i], Be) ^ Be;
    }
    Be = Be - S[1];
    Ay = Ay - S[0];

    word * res = (word *) malloc(sizeof(word) * 2);
    res[0] = Ay;
    res[1] = Be;
    return res;
}

int main(int argc, char **argv) // prog_name, enc?, W, R, B, in, out, [len]
{
    int enc;
    sscanf(argv[1], "%d", &enc);
    sscanf(argv[2], "%d", &W);
    sscanf(argv[3], "%d", &R);
    sscanf(argv[4], "%d", &B);

    char *sin = argv[5];
    char *sout = argv[6];
    FILE *fin = fopen(sin,"r");
    FILE *fout = fopen(sout,"w");

    int len = 0;
    if(!enc) sscanf(argv[7],"%d",&len);

    byte K[B];
for(int i = 0; i < B; i++)
    K[i] = 0;

    word *S = key_expand(K);

    int i = 0,j,k = 0,l=0;
    char plain[U*2], *cipher; // 2 blocks of plaintext and ciphertext
    word Ay,Be;
    while(!feof(fin))
    {   
        plain[i++] = fgetc(fin);
        l++;
        if(i == U*2)
        {
            Ay = ((word *) plain)[0];
            Be = ((word *) plain)[1];
            
            cipher = (char *) (enc == 1 ? encrypt_blocks(Ay, Be, S) : decrypt_blocks(Ay,Be,S));
            for(j = 0; j < U*2; j++,k++)
            {
                if(!enc && k == len) break;
                fputc(cipher[j],fout);
            }
            i = 0;
        }
    }
    fprintf(stderr,"and: %d\n",plain[i-1]);
    
    if(enc)
    {
        for(i--;i< U*2; i++)
        {
            plain[i] = 0;
        }
        Ay = ((word *) plain)[0];
        Be = ((word *) plain)[1];

        cipher = (char *) encrypt_blocks(Ay, Be, S);
        for(i = 0; i < U*2; i++)
        {
            fputc(cipher[i],fout);
        }
        fprintf(stderr, "%d", l);
    }


/*    word Ay = 0;
    word Be = 0;
    word *res = encrypt_blocks(Ay, Be, key_expand(K));
    printf("%x %x", res[0],res[1]);

    word *pla = decrypt_blocks(res[0], res[1], key_expand(K));

    printf("%x %x", pla[0],pla[1]);*/

}
