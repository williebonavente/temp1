#include <stdio.h>
#include <stdlib.h>
int dispensed(int *);

int main(void)
{

    int inp_amount;

    do
    {
        printf("Enter the amount (multiples of 10): ");
        scanf("%d", &inp_amount);

    } while (inp_amount % 10 != 0);
    system("cls");
    printf("Amount Input: %d\n", inp_amount);
    dispensed(&inp_amount);
    
    return 0;
}

int dispensed(int *amount)
{
    double fifties, twenties, tenths;

    tenths = *amount / 10;
    printf("You need to dispensed %.0f $10\n", tenths);
    twenties = *amount / 20;
    printf("You need to dispensed %.0f $20\n", twenties);
    fifties = *amount / 50;
    printf("You need to dispensed %.0f $50\n", fifties);

    return 0;
}
