#include <stdio.h>

int main(void)
{

    float H, k, A, T2, T1, X;
    printf("Enter k >>  ");
    scanf_s("%f", &k);
    printf("Enter A >>  ");
    scanf_s("%f", &A);
    printf("Enter T2 >>  ");
    scanf_s("%f", &T2);
    printf("Enter T1 >>  ");
    scanf_s("%f", &T1);
    printf("Enter k >>  ");
    scanf_s("%f", &X);
    H = (k * A) * (T2 - T1) / (X);

    printf("The value of h = %.2f", H); 

    return 0;
}