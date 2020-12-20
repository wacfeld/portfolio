#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int W;
int R;
int B;

// do not modify these without modifying typedef of word and key
//#define W 32 //word size in bits
#define U (W/8) //word size in bytes
//#define R 20 //number of rounds
//#define B 16 //key size in bytes
#define C (MAX(1, (int) ceil(8 * B/W)))
#define T (2 * (R+1))

typedef uint64_t word;
//typedef unsigned char key[B];

typedef unsigned char byte;

