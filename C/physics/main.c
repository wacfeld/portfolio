#include <stdio.h>
#include <math.h>

struct ball
{
    float rad;
    float mas;
    float pos[2];
    float vel[2];
};

float dist(struct ball b1, struct ball b2)
{
    float q1 = b1.pos[0] - b2.pos[0];
    float q2 = b1.pos[1] - b2.pos[1];
    return sqrt(pow(q1,2) + pow(q2,2));
}

void bounce(float * out, struct ball b1, struct ball b2, float rest)
{
    float m1 = b1.mas, m2 = b2.mas;
    float v1x = b1.vel[0], v1y = b1.vel[1], v2x = b2.vel[0], v2y = b2.vel[1];

    float ms = m1 + m2;

    float v1x_aft = rest * (m1*v1x + 2*m2*v2x - m2*v1x) / ms;
    float v1y_aft = rest * (m1*v1y + 2*m2*v2y - m2*v1y) / ms;
    float v2x_aft = rest * (m2*v2x + 2*m1*v1x - m1*v2x) / ms;
    float v2y_aft = rest * (m2*v2y + 2*m1*v1y - m1*v2y) / ms;

    float all[4] = {v1x_aft, v1y_aft, v2x_aft, v2y_aft};
    for(int i = 0; i < 4; i++)
    {
        out[i] = all[i];
    }
}

int main()
{
    float rest = 0.9;
    int max_x = 100;
    int max_y = 10;
    struct ball b1 = {1, 1, {10,0}, {0.02,0}};
    struct ball b2 = {1, 1, {20,0}, {-0.05,0}};

    for(int i = 0; i < 2000; i++)
    {
        if(dist(b1, b2) <= b1.rad+b2.rad)
        {
            float aft[4];
            bounce(aft, b1, b2, rest);
            b1.vel[0] = aft[0], b2.vel[0] = aft[1];
            b2.vel[0] = aft[2], b2.vel[1] = aft[3];
        }

        if(b1.pos[0] <= 0)
        {
            b1.vel[0] = abs(b1.vel[0]);
        }
        if(b1.pos[0] >= max_x)
        {
            b1.vel[0] = (-1) * abs(b1.vel[0]);
        }
        if(b2.pos[0] <= 0)
        {
            b2.vel[0] = abs(b2.vel[0]);
        }
        if(b2.pos[0] >= max_x)
        {
            b2.vel[0] = (-1) * abs(b2.vel[0]);
        }


        b1.pos[0] += b1.vel[0], b1.pos[1] += b1.vel[1];
        b2.pos[0] += b2.vel[0], b2.pos[1] += b2.vel[1];
        
        int x1r = round(b1.pos[0]);
        int x2r = round(b2.pos[0]);

        int pad = x1r < x2r ? x1r : x2r;
        int spc = (x1r < x2r ? x2r : x1r) - pad;
        for(int i = 0; i < pad; i++)
        {
            printf(" ");
        }
        printf("*");
        for(int i = 0; i < spc; i++) printf(" ");
        printf("*\n");

    }

}