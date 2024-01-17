#include <stdio.h>
#include <stdlib.h>

int main() {
    int exactValue, approximateValue;

    printf("Enter the exact value: ");
    scanf("%d", &exactValue);

    printf("Enter the approximate value (roundoff case): ");
    scanf("%d", &approximateValue);

    // Roundoff case
    int roundoffAbsoluteError = abs(exactValue - approximateValue);
    float roundoffRelativeError = (float)roundoffAbsoluteError / exactValue;
    float roundoffPercentageError = roundoffRelativeError * 100;

    printf("\nRoundoff case:\n");
    printf("Absolute Error: %d\n", roundoffAbsoluteError);
    printf("Relative Error: %.6f\n", roundoffRelativeError);
    printf("Percentage Error: %.6f%%\n", roundoffPercentageError);

    printf("\nEnter the approximate value (truncation case): ");
    scanf("%d", &approximateValue);

    // Truncation case
    int truncationAbsoluteError = abs(exactValue - approximateValue);
    float truncationRelativeError = (float)truncationAbsoluteError / exactValue;
    float truncationPercentageError = truncationRelativeError * 100;

    printf("\nTruncation case:\n");
    printf("Absolute Error: %d\n", truncationAbsoluteError);
    printf("Relative Error: %.6f\n", truncationRelativeError);
    printf("Percentage Error: %.6f%%\n", truncationPercentageError);

    return 0;
}
