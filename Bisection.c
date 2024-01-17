#include <stdio.h>
#include <math.h>
float fun(float x)
{
    return (pow(x,3) - (4*x) - 9);
}
int main()
{
    int m, n, x1, x2, x3, i;
    float a, b;

    printf("\nEnter the range: ");
    scanf("%d %d", &m, &n);

    for(i=m; i<=n; i++)
    {
        if(fun((float)i)*fun((float)(i+1))<0)
        {
            a = (float)i;
            b = (float)(i+1);
            break;
        }
    }
    printf("\nValue of a is %f and b is %f", a, b);
    i=1;
    float x;
    x=(a+b)/2;
    do
    {
        printf("\nValue at iteration x%d is %f", i, x);
        if(fun(a)*fun(x)<0)
            b=x;
        else if(fun(b)*fun(x)<0)
            a=x;
        
        i++;
        x=(a+b)/2;
    } while (fabs(x-a)>=0.0001 || fabs(x-b)>=0.0001);
    
}