#include <stdio.h>

#define MAX_SIZE 100

double gaussForwardInterpolation(double x, int n, double xi[], double fi[]);

int main() {
    int n, i;
    double x, xi[MAX_SIZE], fi[MAX_SIZE], result;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data points (x, f(x)):\n");
    for (i = 0; i < n; i++) {
        printf("x%d: ", i);
        scanf("%lf", &xi[i]);
        printf("f(x%d): ", i);
        scanf("%lf", &fi[i]);
    }

    printf("Enter the value of x for interpolation: ");
    scanf("%lf", &x);

    result = gaussForwardInterpolation(x, n, xi, fi);
    printf("Interpolated value at x = %.2lf is %.4lf\n", x, result);

    return 0;
}

double gaussForwardInterpolation(double x, int n, double xi[], double fi[]) {
    int i, j, k;
    double h, p, yp, result = 0;
    double forwardDiff[MAX_SIZE][MAX_SIZE];

    for (i = 0; i < n; i++) {
        forwardDiff[i][0] = fi[i];
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            forwardDiff[i][j] = forwardDiff[i + 1][j - 1] - forwardDiff[i][j - 1];
        }
    }

    h = xi[1] - xi[0];
    p = (x - xi[0]) / h;
    yp = 1;

    for (k = 0; k < n; k++) {
        result += (yp * forwardDiff[0][k]) / yp;
        yp *= (p - k);
    }

    return result;
}

/*Enter the number of data points: 5
Enter the data points (x, f(x)):
x0: 1
f(x0): 0.2
x1: 2
f(x1): 0.4
x2: 3
f(x2): 0.6
x3: 4
f(x3): 0.8
x4: 5
f(x4): 1.0
Enter the value of x for interpolation: 0.2345
Interpolated value at x = 0.23 is 0.4000*/