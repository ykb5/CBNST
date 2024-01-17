/* Program: Finding real roots of nonlinear
   equation using Fixed Point Iteration
   Author: CodeSansar
   Date: November 18, 2018 */
/* Header Files */
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

/* Define function f(x) which
   is to be solved */
#define   f(x)   cos(x)-3*x+1
/* Write f(x) as x = g(x) and
   define g(x) here */
#define   g(x)   (1+cos(x))/3

int main()
{
	 int step=1, N;
	 float x0, x1, e;

	 /* Inputs */
	 printf("Enter initial guess: ");
	 scanf("%f", &x0);
	 printf("Enter tolerable error: ");
	 scanf("%f", &e);
	 printf("Enter maximum iteration: ");
	 scanf("%d", &N);
	 /* Implementing Fixed Point Iteration */
	 printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
	 do
	 {
		  x1 = g(x0);
		  printf("%d\t%f\t%f\t%f\t%f\n",step, x0, f(x0), x1, f(x1));
		
		  step = step + 1;
		
		  if(step>N)
		  {
			   printf("Not Convergent.");
			   exit(0);
		  }
		  
		  x0 = x1;
		  
	 }while( fabs(f(x1)) > e);
	 
	 printf("\nRoot is %f", x1);

	 return(0);
}
/*Enter initial guess: 1
Enter tolerable error: 0.0001
Enter maximum iteration: 7

Step    x0              f(x0)           x1              f(x1)
1       1.000000        -1.459698       0.513434        0.330761
2       0.513434        0.330761        0.623688        -0.059333
3       0.623688        -0.059333       0.603910        0.011391
4       0.603910        0.011391        0.607707        -0.002162
5       0.607707        -0.002162       0.606986        0.000411
6       0.606986        0.000411        0.607124        -0.000078

Root is 0.607124*/