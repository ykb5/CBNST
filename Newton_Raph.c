#include <stdio.h>
#include <math.h>

#define MAX_ITER 100
#define EPSILON 0.000001

// Function for which we want to find the root
double f(double x) {
    return x * x - 4;
}

// Derivative of the function
double f_derivative(double x) {
    return 2 * x;
}

// Newton-Raphson method
double newton_raphson(double x0) {
    double x = x0;
    int iteration = 0;

    while (fabs(f(x)) > EPSILON && iteration < MAX_ITER) {
        x = x - (f(x) / f_derivative(x));
        iteration++;
    }

    return x;
}

int main() {
    double initial_guess;
    printf("Enter the initial guess: ");
    scanf("%lf", &initial_guess);

    double root = newton_raphson(initial_guess);

    printf("Approximate root: %lf\n", root);
    printf("Function value at root: %lf\n", f(root));

    return 0;
}