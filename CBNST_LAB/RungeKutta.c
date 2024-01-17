#include <stdio.h>

// Function representing the differential equation (change this according to your equation)
float f(float x, float y) {
    return x + y;
}

// Runge-Kutta method implementation
float rungeKutta(float x0, float y0, float x, float h) {
    int n = (int)((x - x0) / h);
    float k1, k2, k3, k4;
    float y = y0;

    for (int i = 1; i <= n; i++) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x0 + h, y + k3);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
    }

    return y;
}

int main() {
    float x0, y0, x, h;

    printf("Enter initial condition x0: ");
    scanf("%f", &x0);
    printf("Enter initial condition y0: ");
    scanf("%f", &y0);
    printf("Enter the value of x for which you want to find y: ");
    scanf("%f", &x);
    printf("Enter the step size h: ");
    scanf("%f", &h);

    float result = rungeKutta(x0, y0, x, h);
    printf("The value of y at x = %f is %f\n", x, result);

    return 0;
}
/*Enter initial condition x0: 0
Enter initial condition y0: 2
Enter the value of x for which you want to find y: 2
Enter the step size h: 0.5
The value of y at x = 2.000000 is 19.151911*/