#include <stdio.h>

void print_ans(float *H, float *k, float *A, float *T2, float *T1, float *X);
void frac_disp(void);
float calc_h(float *H, float k, float A, float T2, float T1, float X);
float calc_k(float H, float *k, float A, float T2, float T1, float X);
float calc_A(float H, float k, float *A, float T2, float T1, float X);
float calc_T2(float H, float k, float A, float *T2, float T1, float X);
float calc_T1(float H, float k, float A, float T2, float *T1, float X);
float calc_X(float H, float k, float A, float T2, float T1, float *X);

int main(void)
{
    float heat_trans, thermal_conduct, conductor_area, temperature_two, temperature_one, thickness;

    // Scanning Question Marks
    char qm, qm1, qm2, qm3, qm4, qm5;

    float x; // placeholder for the return ouput of functions

    printf("Respond to the following prompt with data known. \n");
    printf("For the unknown quantity, enter a question mark (?). \n");

    printf("Rate of heat transfer (watts) >> ");
    scanf_s("%f", &heat_trans);
    scanf_s("%c", &qm);

    printf("Coefficient of thermal conductivity (W/m-k) >> ");
    scanf_s("%f", &thermal_conduct);
    scanf_s("%c", &qm1);

    printf("Cross-sectional area of conductor (m^2) >> ");
    scanf_s("%f", &conductor_area);
    scanf_s("%c", &qm2);

    printf("Temperature on one side (K) >> ");
    scanf_s("%f", &temperature_two);
    scanf_s("%c", &qm3);

    printf("Temperature on the other side (K) >> ");
    scanf_s("%f", &temperature_one);
    scanf_s("%c", &qm4);

    printf("Thickness of  conductor (m) >> ");
    scanf_s("%f", &thickness);
    scanf_s("%c", &qm5);

    if (qm == '?')
    {
        x = calc_h(&heat_trans, thermal_conduct, conductor_area, temperature_two, temperature_one, thickness);
        frac_disp();
        printf("Rate of heat transfer is  %.2f watts. \n", x);
    }

    if (qm1 == '?')
    {
        x = calc_k(heat_trans, &thermal_conduct, conductor_area, temperature_two, temperature_one, thickness);
        frac_disp();
        printf("Coefficient of thermal conductivity is %.2f (W/m-K).\n", x);
    }

    if (qm2 == '?')
    {
        x = calc_A(heat_trans, thermal_conduct, &conductor_area, temperature_two, temperature_one, thickness);
        frac_disp();
        printf("Cross-sectional area of conductor is %.2f m^2. \n", x);
    }

    if (qm3 == '?')
    {
        x = calc_T2(heat_trans, thermal_conduct, conductor_area, &temperature_two, temperature_one, thickness);
        frac_disp();
        printf("Temperature on one side is %.2f K.\n", x);
    }

    if (qm4 == '?')
    {
        x = calc_T1(heat_trans, thermal_conduct, conductor_area, temperature_two, &temperature_one, thickness);
        frac_disp();
        printf("The temperature on the other side is %.2f K.\n", x);
    }

    if (qm5 == '?')
    {
        x = calc_X(heat_trans, thermal_conduct, conductor_area, temperature_two, temperature_one, &thickness);
        frac_disp();
        printf("Thickness of conductor is %g m.\n", x);
    }

    print_ans(&heat_trans, &thermal_conduct, &conductor_area, &temperature_two, &temperature_one, &thickness);

    return 0;
}

float calc_h(float *H, float k, float A, float T2, float T1, float X)
{
    *H = (k * A) * (T2 - T1) / (X);
    return *H;
}

float calc_k(float H, float *k, float A, float T2, float T1, float X)
{
    *k = (H * X) / ((A * T2) - (A * T1));
    return *k;
}

float calc_A(float H, float k, float *A, float T2, float T1, float X)
{
    *A = (H * X) / ((k * T2) - (k * T1));
    return *A;
}

float calc_T2(float H, float k, float A, float *T2, float T1, float X)
{
    *T2 = ((H * X) + (k * A * T1)) / (k * A);
    return *T2;
}

float calc_T1(float H, float k, float A, float T2, float *T1, float X)
{
    *T1 = ((H * X) - (k * A * T2)) / (-k * A);
    return *T1;
}

float calc_X(float H, float k, float A, float T2, float T1, float *X)
{
    *X = (k * A) * (T2 - T1) / (H);
    return *X;
}

void print_ans(float *H, float *k, float *A, float *T2, float *T1, float *X)
{
    printf("H = %.2f \t T2 = %.2f\n", *H, *T2);
    printf("k = %.2f \t T1 = %.2f\n", *k, *T1);
    printf("A = %.2f \t X = %g\n", *A, *X);
}

void frac_disp(void)
{
    printf("\n");
    printf("\tkA(T2 - T1)\n");
    printf("H = ------------------\n");
    printf("\t    X\n\n");
}