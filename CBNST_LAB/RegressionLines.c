#include<math.h>
#include<stdio.h>
int main(){
   int n,i;
   float x,y,m,c,d;
   float sumx=0,sumxsq=0,sumy=0,sumxy=0;
   printf("enter the number of values for n:");
   scanf("%d",&n);
   for(i=0;i<n;i++){
      printf("enter values of x and y\n");
      scanf("%f%f",&x,&y);
      sumx=sumx+x;
      sumxsq=sumxsq+(x*x);
      sumy=sumy+y;
      sumxy=sumxy+(x*y);
   }
   d=n*sumxsq-sumx*sumx;
   m=(n*sumxy-sumx*sumy)/d;
   c=(sumy*sumxsq-sumx*sumxy)/d;
   printf("M=%f\tC=%f",m,c);
   return 0;
}
/*enter the number of values for n:4
enter values of x and y
5
6
enter values of x and y
7
5
enter values of x and y
8
2
enter values of x and y
4
5
M=-0.700000     C=8.700000*/