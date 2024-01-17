//Wap to find absolute error,relative error and percentage error
#include<stdio.h>
#include<math.h>
float roundOff(float X,int pos)
{
    int n;
    X=X*pow(10,pos+1);
    n=X;
    int rem=n%10;
    n/=10;
    if(rem>=5)
    {
        n+=1;
    }
    X=n/pow(10,pos);
    return X;
}
float truncate(float X,int pos)
{
    int n;
    X=X*pow(10,pos);
    n=X;
    X=n/pow(10,pos);
    return X;
}
float absoluteError(float num,float _num)
{
    return fabs(num-_num);
}
float relativeError(float num,float _num)
{
    return (absoluteError(num,_num))/num;
}
float percentageError(float num,float _num)
{
    return (relativeError(num,_num))*100;
}
int main()
{

    float X,_X;
    int pos;
    printf("Enter the true value:");
    scanf("%f",&X);
    printf("\nEnter the digits after decimal places:");
    scanf("%d",&pos);
    _X=roundOff(X,pos);
    printf("\nWhen Roundoff is used:");
    printf("\nAbsolute error:%f",absoluteError(X,_X));
    printf("\nRelative error:%f",relativeError(X,_X));
    printf("\nPercentage error:%f",percentageError(X,_X));
    _X=truncate(X,pos);
    printf("\nWhen Truncation is used:");
    printf("\nAbsolute error:%f",absoluteError(X,_X));
    printf("\nRelative error:%f",relativeError(X,_X));
    printf("\nPercentage error:%f",percentageError(X,_X));
    return 0;
}