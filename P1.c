//C program for finding Error
#include <stdio.h>
int main()
{

    float f1, f2, ab, rel, per;
    scanf("%f %f", &f1, &f2);

    printf("%f %f\n", f1, f2);

    ab = f1 - f2;
    rel = (f1 - f2) / f1;
    per = rel * 100;

    printf("Absolute Error: %f\n", ab);
    printf("Relative Error: %f\n", rel);
    printf("Percentage Error: %f\n", per);

    return 0;
}