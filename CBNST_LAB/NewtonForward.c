#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate the value of the term (x - 1)(x - 2)...(x - n)
int term(int x, int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= (x - i);
    }
    return result;
}

// Function to calculate the forward difference table
void calculateDifferenceTable(int n, float x[], float y[][n]) {
    // Calculating the forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
        }
    }
}

// Function to interpolate using Newton's forward difference formula
float interpolate(int n, float x[], float y[][n], float value) {
    float result = y[0][0];
    float termVal = 1;
    float u = (value - x[0]) / (x[1] - x[0]);

    // Calculating interpolation using Newton's forward difference formula
    for (int i = 1; i < n; i++) {
        termVal *= u - i + 1;
        result += (termVal * y[0][i]) / factorial(i);
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n][n];

    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    calculateDifferenceTable(n, x, y);

    float value;
    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    float result = interpolate(n, x, y, value);
    printf("Interpolated value at %.2f = %.4f\n", value, result);

    return 0;
}
/*Enter the number of data points: 4
Enter the values of x:
x[0] = 32
x[1] = 65
x[2] = 23
x[3] = 65
Enter the values of y:
y[0] = .765
y[1] = .432
y[2] = .456
y[3] = 432
Enter the value to interpolate: 5
Interpolated value at 5.00 = -299.9604*/