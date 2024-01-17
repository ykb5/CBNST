#include <stdio.h>

double trapezoidal_rule(double x[], double y[], int n) {
    double integral = 0.0;
    for (int i = 1; i < n; i++) {
        double segment = (x[i] - x[i-1]) * (y[i] + y[i-1]) / 2.0;
        integral += segment;
    }
    return integral;
}

int main() {
    // Sample data
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[] = {2.0, 3.0, 5.0, 4.0, 6.0};
    int n = sizeof(x) / sizeof(x[0]);  // Number of data points

    double result = trapezoidal_rule(x, y, n);

    printf("Integral: %.2f\n", result);

    return 0;
}
/*Integral: 16.00*/