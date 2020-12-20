#include <stdio.h>
#include <wchar.h>

int main()
{
    int c;
    while((c = getwchar()) != EOF)
    {
        if(c == 0xE28098 || c == 0xE28099)
        {
            putchar('\'');
        }
        else if(c == 0xE2809C || c == 0XE2809D)
        {
            putchar('"');
        }
        else if(c >= 0XE28090 && c <= 0XE28095)
        {
            putchar('-');
        }
        else putchar(c);
        printf(" %d", c);
        putchar('\n');
    }
}
