#include <stdio.h>
#include <stdlib.h>

void order(double *smp, double *lgp);
void order_inverse(double *smp, double *lgp);

int main(void)
{

    double num1, num2, num3, num4;

    printf("Enter four numbers >> ");
    scanf("%lf%lf%lf%lf", &num1, &num2, &num3, &num4);

    printf("Before Sorting: %.2f %.2f %.2f %.2f\n", num1, num2, num3, num4);

    // Ascending Order
    order(&num1, &num2);
    order(&num1, &num3);
    order(&num1, &num4);
    order(&num2, &num4);
    order(&num2, &num3);

    printf("Sorted (Ascending Order): %.2f %.2f %.2f %.2f\n", num1, num2, num3, num4);

    order_inverse(&num2, &num4);
    order_inverse(&num2, &num3);
    order_inverse(&num1, &num4);
    order_inverse(&num1, &num3);
    order_inverse(&num1, &num2);

    printf("Sorted (Descending Order): %.2f %.2f %.2f %.2f\n", num1, num2, num3, num4);

    return EXIT_SUCCESS;
}

void order(double *smp, double *lgp)
{
    double temp; // placeholder for swapping

    // Compares value
    if (*smp > *lgp)
    {
        temp = *smp;
        *smp = *lgp;
        *lgp = temp;
    }
}

void order_inverse(double *smp, double *lgp)
{
    double temp;

    if (*smp < *lgp)
    {
        temp = *smp;
        *smp = *lgp;
        *lgp = temp;
    }
}
