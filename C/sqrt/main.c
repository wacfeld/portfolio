#include <stdio.h>


#define putf(x) printf("%.10f\n",x)
#define putd(x) printf("%d\n",x)

typedef struct { double a0, a1, a2, a3, a4, a5; } quint;

quint der(quint q)
{
    quint d = {q.a1, 2*q.a2, 3*q.a3, 4*q.a4, 5*q.a5, 0};
    return d;
}

double eval(quint q, double x)
{
    return q.a0 + x*q.a1 + x*x*q.a2 + x*x*x*q.a3 + x*x*x*x*q.a4 + x*x*x*x*x*q.a5;
}

int main()
{
    quint q = {4.5,-1,2,1.1,-0.8,0.1};
    quint d = der(q);

    double x;
    double iota = 0.00001;
    double step = 0.0001;

    for(double i = -2; i < 5; i+=step)
    {
        printf("%f %f\n",i, eval(q,i));
    }

    printf("nex\n");
    //descend
    double ex[] = {-.5,1,3,5};
    for(int j = 0; j <sizeof(ex)/sizeof(double); j++)
    {
        x = ex[j];
        for(int i = 0; i < 100000; i++)
        {
            double delta = (-iota) * eval(d, x);
            x += delta;
            printf("%f %f\n", x, eval(q, x));
        }
        printf("nex\n");
    }
    // plot
    printf("out\n");
}
