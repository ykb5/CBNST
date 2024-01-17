#include <stdio.h>

#define SIZE 10

void gaussElimination(float matrix[SIZE][SIZE + 1], int n)
{
    int i, j, k;
    float factor, temp;

    for (i = 0; i < n - 1; i++)
    {
        if (matrix[i][i] == 0)
        {
            printf("Pivot element is zero. The system has no unique solution.\n");
            return;
        }

        for (j = i + 1; j < n; j++)
        {
            factor = matrix[j][i] / matrix[i][i];
            for (k = i; k < n + 1; k++)
            {
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
            }
        }
    }

    if (matrix[n - 1][n - 1] == 0)
    {
        printf("Pivot element is zero. The system has no unique solution.\n");
        return;
    }

    float solution[SIZE];
    solution[n - 1] = matrix[n - 1][n] / matrix[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        temp = 0;
        for (j = i + 1; j < n; j++)
        {
            temp = temp + matrix[i][j] * solution[j];
        }
        solution[i] = (matrix[i][n] - temp) / matrix[i][i];
    }

    printf("Solution:\n");
    for (i = 0; i < n; i++)
    {
        printf("x%d = %f\n", i + 1, solution[i]);
    }
}

int main()
{
    int n, i, j;
    float matrix[SIZE][SIZE + 1];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix coefficients row-wise:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            scanf("%f", &matrix[i][j]);
        }
    }

    gaussElimination(matrix, n);

    return 0;
}
/*Enter the number of equations: 3
Enter the augmented matrix coefficients row-wise:
1
4
5
6
7
6
5
4
4
3
3
3
Solution:
x1 = 0.000001
x2 = -1.000001
x3 = 2.000001*/