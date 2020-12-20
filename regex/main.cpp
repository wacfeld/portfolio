/* symbols
	? - 0 or 1 of preceding element
	* - 0 or more of preceding element
	+ - one or more of preceding element
	. any character
*/

#include <iostream>

bool is_sym(char c)
{
    return (c == '?' || c == '*' || c == '+' || c == '.');
}

int get_adjlen(std::string pat)
{
    int l = 0;
    for(char c : pat)
    {
        if(!is_sym(c) || c == '.') ++l;
    }
    return l;
}

char * parse_pat(std::string pat)
{
    int adjlen = get_adjlen(pat);
    
    char * enc = new char[200];
    char * pln = new char[100];
    char * sym = new char[100];

    for(int i = 0; i < 100; ++i)
    {
        pln[i] = '/';
        sym[i] = '/';
    }

    int i = 0;
    for(char c : pat)
    {
        if(!is_sym(c))
        {
            pln[i] = c;
            sym[i] = '0';
            ++i;
        }
        else
        {
            if(c == '.')
            {
                pln[i] = '.';
                sym[i] = '.';
                ++i;
            }
            else
            {
                sym[i-1] = c;
            }
        }
    }

    for(int i = 0; i < 100; ++i)
    {
        enc[i] = pln[i];
        enc[i+100] = sym[i];
    }

    return enc;
}

int get_len(char * str)
{
    
    int len = 0;
    while(str[len] != '/')
    {
        ++len;
    }
    return len;
}

char * trim_str(char * str)
{
    char * out = new char[100];
    int len = get_len(str);
    for(int i = 0; i < len; i++)
    {
        out[i] = str[i+1];
    }
    out[99] = str[99];
    return out;
}

char * cp_str(char * in)
{
    char * out = new char[100];
    for(int i = 0; i < 100; i++)
    {
        out[i] = in[i];
    }

    return out;
}

// void print_pn(char * pn[2][3], int np)
// {
//     std::cout << "in print_pn\n";
//     for(int i = 0; i < np; i++)
//     {
//         for(int j = 0; j < 3; j++)
//         {
//             std::cout << pn[i][j] << " ";
//         }
//         std::cout << std::endl;
//     }
//     std::cout << "done\n" << std::endl;
// }

// void print_up(char * str)
// {
//     for(int i = 0; i < get_len(str); i++)
//     {
//         std::cout << str[i];
//     }
//     std::cout << "/ ";
// }

bool has_match(char * txt, char * pln, char * sym)
{
    if(get_len(pln) == 0) return true;
    
    char * pos_next[2][3];

    int num_pos = 1;
    bool tt0, pt0, st0, tt1, pt1, st1;
    bool m = false;

    // print_up(txt);
    // print_up(pln);
    // print_up(sym);
    // std::cout << std::endl;
    
    if(sym[0] == '0')
    {
        if(txt[0] == pln[0])
        {
            tt0 = true, pt0 = true, st0 = true, m = true;
        }
    }
    else if(sym[0] == '.')
    {
        if(txt[0] != '/')
        {
            tt0 = true, pt0 = true, st0 = true, m = true;
        }
    }
    else if(sym[0] == '*')
    {
        tt0 = false, pt0 = true, st0 = true, m = true;
        if(txt[0] == pln[0])
        {
            tt1 = true, pt1 = false, st1 = false;
            num_pos = 2;
        }
    }
    else if(sym[0] == '+')
    {
        if(txt[0] == pln[0])
        {
            sym[0] = '*';
            tt0 = true, pt0 = false, st0 = false, m = true;
        }
    }
    else if(sym[0] == '?')
    {
        tt0 = false, pt0 = true, st0 = true, m = true;
        if(txt[0] == pln[0])
        {
            tt1 = true, pt1 = true, st1 = true;
            num_pos = 2;
        }
    }

    if(!m)
    {
        return false;
    }


    pos_next[0][0] = tt0 ? trim_str(txt) : cp_str(txt);
    pos_next[0][1] = pt0 ? trim_str(pln) : cp_str(pln);
    pos_next[0][2] = st0 ? trim_str(sym) : cp_str(sym);
    if(num_pos == 2)
    {
        pos_next[1][0] = tt1 ? trim_str(txt) : cp_str(txt);
        pos_next[1][1] = pt1 ? trim_str(pln) : cp_str(pln);
        pos_next[1][2] = st1 ? trim_str(sym) : cp_str(sym);
    }

    bool match = false;
    for(int i = 0; i < num_pos; i++)
    {
        match |= has_match(pos_next[i][0], pos_next[i][1], pos_next[i][2]);
    }

    return match;
}

int main()
{
    std::cout << "program start\n";
    
    char * text = "colour/";
    std::string pattern = "co.our";

    std::cout << "parsing...\n";
    char * enc = parse_pat(pattern);
    std::cout << "  done\n";

    std::cout << "decoding...\n";
    char * pln = new char[100];
    char * sym = new char[100];
    for(int i = 0; i < 100; i++)
    {
        pln[i] = enc[i];
        sym[i] = enc[i+100];
    }
    std::cout << "  done\n";

    std::cout << "matching...\n";
    bool match = false;

    int text_len = get_len(text);
    for(int i = 0; i < text_len + 1; i++)
    {
        if(i == 0)
        {
            match |= has_match(text, pln, sym);
            continue;
        }
        
        text = trim_str(text);
        bool m = has_match(text, pln, sym);
        if(m)
        {
            match = true;
            break;
        }
    }
    std::cout << "  done\n";

    std::cout << "\n";
    std::cout << (match ? "match" : "no match") << std::endl;
}
