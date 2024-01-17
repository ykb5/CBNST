// Newton -Raphson
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define g(x) (x*x*x +1)/2
#define f(x) (x*x*x-2*x+1)
// double f(double x)
// {
//     return (x*x*x-2*x*x-4);
// }
// double g(double y)
// {   double value=2*y*y+4;
//     value=pow(value,0.33333);
//     return value;
// }
int main()
{
    double a,b;
    double x[20];
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
    while(1)
    {
        x[i]=g(x[i-1]);
        printf("Iteration:%d and value of x:%lf\n",i,x[i]);
         if(i>=3){   if(fabs(x[i]-x[i-1])<=0.0009 &&fabs(x[i-1]-x[i-2])<=0.0009)
            {  
                printf("\nIterations:%d",i);
                printf("\nRoot:%lf",x[i]);
                flag=1;
                break;
            }}
        i++;
    }
    printf("\nValue of function:%.6f",f(x[i]));
return 0;
}