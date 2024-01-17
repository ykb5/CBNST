#include <stdio.h>

// Function representing the derivative of the function y
double dy(double x, double y) {
    // Example: dy/dx = 2x + y
    return 2 * x + y;
}

// Euler's method implementation
void eulerMethod(double x0, double y0, double h, double x_target) {
    double x = x0;
    double y = y0;

    while (x < x_target) {
        printf("x = %f, y = %f\n", x, y);
        y += h * dy(x, y);
        x += h;
    }

    // Print the final result
    printf("x = %f, y = %f\n", x, y);
}

int main() {
    double x0, y0, h, x_target;

    // Read initial values and step size
    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter step size (h): ");
    scanf("%lf", &h);
    printf("Enter target value of x: ");
    scanf("%lf", &x_target);

    eulerMethod(x0, y0, h, x_target);

    return 0;
}
/*Enter initial value of x (x0): 0
Enter initial value of y (y0): 1
Enter step size (h): 0.1
Enter target value of x: 1
x = 0.000000, y = 1.000000
x = 0.100000, y = 1.100000
x = 0.200000, y = 1.230000
x = 0.300000, y = 1.393000
x = 0.400000, y = 1.592300
x = 0.500000, y = 1.831530
x = 0.600000, y = 2.114683
x = 0.700000, y = 2.446151
x = 0.800000, y = 2.830766
x = 0.900000, y = 3.273843
x = 1.000000, y = 3.781227
x = 1.100000, y = 4.359350*/