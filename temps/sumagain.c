#include <stdio.h>
#include <stdlib.h>

int sum(double *n1, double *n2);

int main(void)
{

    double x = 23, y = 6;
    sum(&x, &y);

    

    return EXIT_SUCCESS;
}

int sum(double *n1, double *n2)
{
    int sum;
    sum = *n1 + *n2;
    printf("Sum is %d", sum);
    return 0;
}