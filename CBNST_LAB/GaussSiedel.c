#include <stdio.h>
#include <math.h>

#define SIZE 3

void gauss_seidel(double matrix[SIZE][SIZE+1], double initial_guesses[SIZE], double tolerance, int max_iterations) {
    double x[SIZE];
    int i, j, iteration;
    double error;

    for (i = 0; i < SIZE; i++) {
        x[i] = initial_guesses[i];
    }

    for (iteration = 1; iteration <= max_iterations; iteration++) {
        error = 0.0;

        for (i = 0; i < SIZE; i++) {
            double sum = matrix[i][SIZE];

            for (j = 0; j < SIZE; j++) {
                if (j != i) {
                    sum -= matrix[i][j] * x[j];
                }
            }

            double new_x = sum / matrix[i][i];
            error += fabs(new_x - x[i]);
            x[i] = new_x;
        }

        if (error <= tolerance) {
            printf("Solution converged after %d iterations.\n", iteration);
            printf("Solution:\n");
            for (i = 0; i < SIZE; i++) {
                printf("x%d = %lf\n", i + 1, x[i]);
            }
            return;
        }
    }

    printf("Solution did not converge after %d iterations.\n", max_iterations);
}

int main() {
    double matrix[SIZE][SIZE+1] = {
        {4, -1, 1, 5},
        {1, 3, -1, 5},
        {1, 1, 4, 11}
    };

    double initial_guesses[SIZE] = {0, 0, 0};
    double tolerance = 0.0001;
    int max_iterations = 100;

    gauss_seidel(matrix, initial_guesses, tolerance, max_iterations);

    return 0;
}
/*Solution converged after 7 iterations.
Solution:
x1 = 1.236370
x2 = 1.909083
x3 = 1.963637*/