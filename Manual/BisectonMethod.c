// Bisection Method
#include <stdio.h>
#include<math.h>
// #define F(x) (x*x*x-2*x-5)
// #define F(x) (x*log10(x)-1.2)
#define F(x) (x*exp(x)-cos(x))
int main()
{
    
    float a,b;
    float res,x[20];
    int flag=0;
    int i=0;
   for(b=1;;b++)
    {
        if(F(b)>0)
        {
            break;
        }
    }
    for(a=b-1;;a--)
    {
        if(F(a)<0)
        {
            break;
        }
    }
    printf("\nValue of a and b:%.2f %.2f\n",a,b);
    while(1){
        x[i]=(a+b)/2.0;
    printf("value of x:%.5f\n",x[i]);
        res=F(x[i]);
        if(F(a) >0 &&res<0 || F(a)<0 && res>0)
        {
            b=x[i];
        }
        else if(res<0 && F(b)>0 || res>0 && F(b)<0)
        {
            a=x[i];
        }
        
            if(i>=3)
            {
                if(fabs(x[i-1]-x[i])<=0.00009 && fabs(x[i-1]-x[i-2])<=0.00009)//Accuracy upto 4 decimal places
                {
                    printf("\nValue of function:%f",F(x[i]));
                    printf("\nNumber of iterations:%d",i+1);
                    flag=1;
                }
            }
            if(flag==1)
            {
                break;
            }
        i++;
    }
    return 0;
}
