//Regular Falsi
#include <stdio.h>
#include<math.h>
// #define F(x) (x*x*x-4*x-9)
// #define F(x) (x*exp(x)-cos(x))
// #define F(x)(x*log10(x)-1.2)
#define F(x) (3*x+sin(x)-exp(x))
int main()
{
    
    float a,b;
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
    printf("Value of a and b :%.2f %.2f",a,b);
    float res,x[20],f1,f2;
    int flag=0;
    int i=2;
    x[0]=a;
    x[1]=b;
    while(1){
        f1=F(a);//function value at a
        f2=F(b);//function value at b
        x[i]=(a*f2-b*f1)/(f2-f1);
        printf("%.5f\n",x[i]);
        res=F(x[i]);
        if(f1>0 &&res<0 || f1<0 && res>0)
        {
            b=x[i];
        }
        else if(res<0 && f2>0 || res>0 && f2<0)
        {
            a=x[i];
        }
        
            if(i>=3)
            {
                if(fabs(x[i-1]-x[i])<=0.00009 && fabs(x[i-1]-x[i-2])<=0.00009)
                {
                    printf("\nValue of function:%f",F(x[i]));
                    printf("\nNumber of iterations:%d",i);
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
