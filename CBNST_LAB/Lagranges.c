#include <stdio.h>

double lagrangeInterpolation(double x[], double y[], int n, double target) {
    double result = 0.0;
    
    for (int i = 0; i < n; i++) {
        double term = y[i];
        
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term *= (target - x[j]) / (x[i] - x[j]);
            }
        }
        
        result += term;
    }
    
    return result;
}

int main() {
    // Example usage
    
    double x[] = {1,2,3,4,5};  // X-values
    double y[] = {0.2,0.4,0.6,0.8,1.0};  // Corresponding Y-values
    int n = 5;                     // Number of data points
    
    double target = 0.2345;           // Target value for interpolation
    
    double interpolatedValue = lagrangeInterpolation(x, y, n, target);
    
    printf("Interpolated value at %.2f: %.2f\n", target, interpolatedValue);
    
    return 0;
}
/*Interpolated value at 0.23: 0.05*/