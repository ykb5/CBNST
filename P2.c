//C program for Truncation and Round Off
#include <stdio.h>
int main()
{

    int n;
    float f1;
    scanf("%f", &f1);
    for (int i = 0; i < 5; i++)
        f1 /= 0.10;

    f1 = (int)f1;
    //printf("Middle: %f\n", f1);
    int inc = 0;

    if ((int)f1 % 10 >= 5)
        inc++;
    f1 = (int)f1 / 10;
    float f2 = f1;
    if (inc)
        f2++;
    for (int i = 0; i < 4; i++)
    {
        f1 *= 0.10;
        f2 *= 0.10;
    }
    printf("Truncated: %.4f\n", f1);
    printf("Round off: %.4f\n", f2);

    return 0;
}