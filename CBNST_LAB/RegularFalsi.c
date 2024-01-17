#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 100
#define EPSILON 0.00001

double f(double x) {
    // Define the function for which you want to find the root
    // Example: return x*x - 4; // for finding the square root of 4
    // (modify this function according to your equation)
    return x*x - 4;
}

double falsePosition(double a, double b) {
    double c;
    int i;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        if (fabs(b - a) < EPSILON)
            break;

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(c) == 0.0)
            break;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }

    printf("Number of iterations: %d\n", i);
    return c;
}

int main() {
    double a, b, root;

    printf("Enter the interval [a, b] for root finding: ");
    scanf("%lf %lf", &a, &b);

    root = falsePosition(a, b);

    printf("Approximate root: %lf\n", root);
    printf("f(root): %lf\n", f(root));

    return 0;
}
/*Enter the interval [a, b] for root finding: 2.345
3.456
Number of iterations: 100
Approximate root: 2.000000
f(root): 0.000000*/