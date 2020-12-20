#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 1000
#define IN 1 // in the token
#define OUT 0 // out of token

char syms[] = "+-*/"; // all symbols must be length one

int is_sym(char c)
{
	char s;
	for(int i = 0; (s = syms[i]) != '\0'; ++i)
		if(s == c)
			return 1;
	return 0;
}

double eval_bin(double n1, double n2, char sym)
{
	switch(sym)
    {
    case '+': return n1 + n2;
    case '-': return n1 - n2;
    case '*': return n1 * n2;
    case '/': return n1 / n2;
    }
}

double calc(char eq[])
{
    double num_stack[MAX_ARR];
    int s = 0; // stack index
    
    char cur_tok[MAX_ARR]; // current token
    int t = 0; // token index
    
    int state = OUT;
    char c; // current char
    for(int i = 0; c = eq[i], eq[i-1] != '\0' || i == 0; ++i) // process '\0' as well
    {
        if(c == '\0') c = ' '; // reaching the end triggers OUT
        
        // don't care if OUT twice
        if(state == OUT && c != ' ') // start recording
        {
            state = IN; // effect on following if statement intentional
        }
        if(state == IN)
        {
            if(c != ' ') // keep recording
            {
                cur_tok[t++] = c;
            }
            else // stop recording, eval & reset cur_tok
            {
                state = OUT;
                cur_tok[t] = '\0';
                if(t == 1 && is_sym(cur_tok[0])) // it's a symbol, do calculation
                {
                    double n1 = num_stack[s-2];
                    double n2 = num_stack[s-1];
                    //printf("%f %f\n", n1, n2);
                    double res = eval_bin(n1, n2, cur_tok[0]);
                    
                    num_stack[s - 2] = res;
                    --s;
                }
                else // it's a number, append to the stack
                {
                    num_stack[s++] = atof(cur_tok);
                }
    
                t = 0; // reset cur_tok
            }
        }
    }
 
    return num_stack[0];
}

int main()
{
    printf("in\n");

    char eq[] = "15 7 1 1 + - / 3 * 2 1 1 + + -";
    double res = calc(eq);
    printf("%f\n", res);
}
