#include <stdio.h>
#include <stdlib.h>

void sum_n_avg(float n1, float n2, float n3, float *sum, float *avg);

int main(void)
{

    float g1, g2, g3, sum, avg;

    printf("Enter 3 Grades (separated by spaces) >>  ");
    scanf("%f %f %f", &g1, &g2, &g3);

    // Function call
    sum_n_avg(g1, g2, g3, &sum, &avg);
    printf("The sum is %.2f\n", sum);
    printf("The average is %.2f\n", avg);

    return EXIT_SUCCESS;
}

void sum_n_avg(float n1, float n2, float n3, float *sum, float *avg)
{
    *sum = n1 + n2 + n3;
    *avg = *sum / 3;
}
