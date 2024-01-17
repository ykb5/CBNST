#include <stdio.h>

#define MAX_DATA_POINTS 100

// Structure to hold x-y data points
typedef struct {
    double x;
    double y;
} DataPoint;

// Function to fit a straight line using curve fitting
void fitStraightLine(DataPoint data[], int numPoints) {
    double sumX = 0.0;
    double sumY = 0.0;
    double sumXY = 0.0;
    double sumX2 = 0.0;

    // Calculate the sums
    for (int i = 0; i < numPoints; i++) {
        sumX += data[i].x;
        sumY += data[i].y;
        sumXY += data[i].x * data[i].y;
        sumX2 += data[i].x * data[i].x;
    }

    // Calculate the slope (m) and y-intercept (c) of the line
    double slope = (numPoints * sumXY - sumX * sumY) / (numPoints * sumX2 - sumX * sumX);
    double yIntercept = (sumY - slope * sumX) / numPoints;

    printf("Equation of the line: y = %.2lfx + %.2lf\n", slope, yIntercept);
}

int main() {
    int numPoints;
    DataPoint data[MAX_DATA_POINTS];

    printf("Enter the number of data points: ");
    scanf("%d", &numPoints);

    if (numPoints <= 0 || numPoints > MAX_DATA_POINTS) {
        printf("Invalid number of data points. Exiting.\n");
        return 1;
    }

    printf("Enter the x-y data points:\n");
    for (int i = 0; i < numPoints; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &data[i].x, &data[i].y);
    }

    // Fit the straight line
    fitStraightLine(data, numPoints);

    return 0;
}
/*Enter the number of data points: 4
Enter the x-y data points:
Point 1: 2
4
Point 2: 4
5
Point 3: 3
3
Point 4: 6
6
Equation of the line: y = 0.63x + 2.14*/