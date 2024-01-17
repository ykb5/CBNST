#include <stdio.h>

#define N 3  // Number of variables

void gauss_jordan_elimination(float matrix[N][N + 1]);

int main() {
    float matrix[N][N + 1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    gauss_jordan_elimination(matrix);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %f\n", i + 1, matrix[i][N]);
    }

    return 0;
}

void gauss_jordan_elimination(float matrix[N][N + 1]) {
    int i, j, k;
    float pivot, factor;

    for (i = 0; i < N; i++) {
        // Find pivot
        pivot = matrix[i][i];

        // Divide the current row by the pivot
        for (j = 0; j < N + 1; j++) {
            matrix[i][j] /= pivot;
        }

        // Elimination
        for (k = 0; k < N; k++) {
            if (k != i) {
                factor = matrix[k][i];
                for (j = 0; j < N + 1; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}
/*Solution:
x1 = 2.000000
x2 = 3.000000
x3 = -1.000000*/