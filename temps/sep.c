#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void sep(double num, char *sign, int *whole, double *frac);

int main()
{

    double value;
    char sn;
    int whole;
    double fr;

    // Gets the data
    printf("Enter a value to analyze > ");
    scanf("%lf", &value);

    // Function Call
    sep(value, &sn, &whole, &fr);

    printf("Parts of %.4f\n sign: %c \n", value, sn);
    printf(" Whole number magnitude: %d\n", whole);
    printf(" Fractional part: %.4f\n", fr);

    return EXIT_SUCCESS;
}

void sep(double num, char *sign, int *whole, double *frac)
{
    double magnitude; // local variable

    // determines sign of num
    if (num < 0)
        *sign = '-';

    else if (num == 0)
        *sign = ' ';

    else
        *sign = '+';

    magnitude = fabs(num);
    *whole = floor(magnitude);
    *frac = magnitude - *whole;
}