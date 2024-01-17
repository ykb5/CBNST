// Newton -Raphson
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
// #define f(x) (x*log10(x)-1.2)
// #define f_x(x) (2.30258+2.30258*log(x))
double f(double x)
{
    // return (x*x*x-2*x-5);
    return (x*x*x-4*x-9);
}
double f_x(double y)
{
    // return(3*y*y-2);
    return (3*y*y-4);
}
int main()
{
    double a,b;
    double x[15];
    for(b=1;;b++)
    {
        if(f(b)>0)
        {
            break;
        }
    }
    for(a=b-1;;a--)
    {
        if(f(a)<0)
        {
            break;
        }
    }
    printf("\nValue of a and b:%.2f %.2f\n",a,b);
    x[0]=(a+b)/2.0;
    int i=1,flag=0;
    // x[1]=x[0]-(f(x[0])/f_x(x[0]));
    while(1)
    {
        x[i]=x[i-1]-(f(x[i-1])/f_x(x[i-1]));
        printf("Iteration:%d and value of x:%lf\n",i,x[i]);
            if(i>=3){
            if(fabs(x[i]-x[i-1])<=0.0009 &&fabs(x[i-1]-x[i-2])<=0.0009)
            {
                printf("\nIterations:%d",i);
                printf("\nRoot:%lf",x[i]);
                printf("\nValue of function for root:%lf",f(x[i]));
                flag=1;
                break;
            }
            }
        i++;
    }
    
return 0;
}