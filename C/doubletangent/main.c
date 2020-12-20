#include <stdio.h>
#include <stdlib.h>

const double H = 0.001;

double calc(double x)
{
    return (-1/20)*(x+4)*(x+2)*(x-1)*(x-5);
}

int rough_equals(double x1, double x2)
{
    printf("%f\n", x1 - x2);
    if(abs(x1-x2) <= H) return 1;
    return 0;
}

double deri(double x)
{
    double left_deri = (calc(x)-calc(x-H))/H;
    double right_deri = (calc(x+H)-calc(x))/H;
    return (left_deri+right_deri)/2;
}

double y_int(double x, double m)
{
    return calc(x) - m*x;
}

// y = mx + b
// b = y - mx

int main(void)
{
    int done = 0;
    double ex1, ex2, em, be;
    for(double x = -4; x <= -3; x += H)
    {
        double m = deri(x);
        double b = y_int(x, m);
        for(double z = 3; z <= 4; z += H)
        {
            double mz = deri(z);
            double bz = y_int(z, mz);
            if(rough_equals(m, mz) == 1 && rough_equals(b, bz) == 1)
            {
                ex1 = x;
                ex2 = z;
                em = m;
                be = b;
                done = 1;
                break;
            }
        }
        
        if(done == 1) break;
    }

    printf("%f %f %f %f", ex1, ex2, em, be);

    return 0;
}
