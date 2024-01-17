#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to calculate Newton's backward difference
float newtonsBackwardDifference(int n, float x[], float y[][n], float value) {
    float result = y[0][n - 1];
    float u = (value - x[n - 1]) / (x[1] - x[0]);

    for (int i = 1; i < n; i++) {
        float term = u;
        for (int j = 1; j <= i; j++) {
            term *= (u + j);
        }
        term /= factorial(i);
        result += term * y[i][n - i - 1];
    }
    return result;
}

int main() {
    int n;  // Number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n][n];  // Arrays to store x and y values

    // Input x and y values
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[0][i]);
    }

    // Calculate backward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];
        }
    }

    // Interpolation
    float value;
    printf("\nEnter the value to interpolate: ");
    scanf("%f", &value);

    float interpolatedValue = newtonsBackwardDifference(n, x, y, value);
    printf("Interpolated value at %.2f is: %.4f\n", value, interpolatedValue);

    return 0;
}
/*Enter the number of data points: 5
Enter the x and y values:
23
54
78
43
23
76
98
32
45
54

Enter the value to interpolate: 4
Interpolated value at 4.00 is: 9.9645*/