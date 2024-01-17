//C program for Bisection Method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b;
    printf("Enter the value of a and b: ");
    scanf("%f %f", &a, &b);
    float l1=pow(a,3)-4*a-9;
    float l2=pow(b,3)-4*b-9;
    if((l1<0 && l2<0) || (l1>0 && l2>0))
    {
        printf("Incorrect\n");
        return 0;
    }
    while(1)
    {
        float m=(a+b)/2;
        l1=pow(a,3)-4*a-9;
        l2=pow(b,3)-4*b-9;
        float temp=pow(m,3)-4*m-9;
        if(fabs(m-a)<0.0001)
        {
            printf("Ans: %f\n", a);
            return 0;
        }
        else if(fabs(m-b)<0.0001)
        {
            printf("Ans: %f\n", b);
            return 0;
        }
        if(temp<0)
        {
            if(l1<0)
                a=m;
            else if(l2<0)
                b=m;
        }
        else
        {
            if(l1>0)
                a=m;
            else if(l2>0)
                b=m;
        }
    }
    return 0;
}