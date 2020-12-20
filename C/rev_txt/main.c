#include <stdio.h>
#include <string.h>
#include <ctype.h>

// if it goes above, put sth in stderr and just cutoff the rest
#define BSIZ 1000 // 1 kb words max
#define OSIZ 100000 // 100 kb inputs max

// don't -> t'nod
// sam's -> s'mas
// wives' -> 'seviw
// "some people" -> "emos elpoep"
// you, why??? -> uoy, yhw???
// i am. hi. -> i ma. ih.
// apostrophes are treated as alnum, but all others are not

int misalnum(int c) // modified isalnum treats apostrophes as alnum
{
    return isalnum(c) || c == '\'';
}

void swap(char *A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

//            if(c >= 128) // deal with unicode
//            {
//                c >>= 3;
//                if(c == 30) // 4 bytes
//                {
//                    buffer[b+3] = c;
//                    buffer[b+2] = getchar();
//                    buffer[b+1] = getchar();
//                    buffer[b] = getchar();
//                    b += 4;
//                    buffer[b]=0;
//                }
//                if(c == 28)
//                {
//                    buffer[b+2] = c;
//                    buffer[b+1] = getchar();
//                    buffer[b] = getchar();
//                    b += 3;
//                    buffer[b]=0;
//                }
//                if(c == 28)
//                {
//                    buffer[b+1] = c;
//                    buffer[b] = getchar();
//                    b += 2;
//                    buffer[b]=0;
//                }
//                strcpy(out+o,buffer);
//                o += b;
//                b = 0;
//                continue;
//            }
//

char buffer[BSIZ]; // contains all the characters between 2 spaces
int b = 0; // index of buffer
char out[OSIZ];
int o = 0; // index of out
int main()
{
    // we reverse each "word" in place, and at the end we print out the whole thing right to left
    // each word is of the form: <punc1><alnum><punc2>
    // only the alphanumerics get reversed
    // probably "[" and "]" will invert themselves, but i won't bother with fixing that
    // " " is non alnum, so that works out nicely
    int c;
    int alnum = 0; // boolean, used later
    int an_start, an_end; // alnum start/end
    int avg;
    for(;;)
    {
        c = getchar();
        if(c != EOF)
        {
                buffer[b++] = c; // log into buffer
        }

        if(!misalnum(c)) // if space, process buffer
        {
            buffer[b] = 0; // null-term string
            alnum = 0;
            //an_start = an_end = 0;
            an_start = 0, an_end = b-1;
/*            for(int i = 0; i < b; i++)
            {
                if(misalnum(buffer[i]))
                {
                    an_start = i;
                    break;
                }
            }
            for(int i = b; i > 0; i--)
            {
                if(misalnum(buffer[i-1]))
                {
                    an_end = i;
                    break;
                }
            }
*/
            if(an_start < an_end) // if needed, reverse the alnums
            {
                avg = (an_start+an_end)/2;
                int i,j;
                for(i = an_start, j = an_end-1; i<j; i++, j--) // start from ends and converge to middle
                {
                    swap(buffer, i, j);
                }
            }
            strcpy(out+o, buffer);
            o += b;
            b = 0;
        }
        if(c == EOF)
            break;
    }


    // dump in reverse order
    for(int i = o-1; i >= 0; i--)
    {
        if((unsigned char) out[i] >= 128) // one one indicate utf8 component
        {
            int p = i-1;
            int q = i;
            while((unsigned char) out[p] < 192) // two or more ones indicate beginning of utf8 char
            {
                p--;
            }
            i = p-1; // skip backwards past the utf8
            for(; p < q; p++, q--)
            {
                swap(out, p, q);
            }
        }
    }
    int i,j;
    for(i = 0, j = o-1; i<j; i++, j--)
    {
        swap(out,i,j);
    }
    out[o] = 0;
    printf("%s",out);
}
