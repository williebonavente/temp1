#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void make_change(double, double, int * , double *);

int main (void) {

    // Localizing

    int num_twenties;
    double remaining_change;

    double amount;
    int token;


    printf("Enter total amount of money >> ");
    scanf("%lf",&amount);
    printf("Enter the token >> ");     
    scanf("%d",&token);

    // Function Call
    make_change(amount, token, &num_twenties, &remaining_change); // multiple results

    printf("Number of twenties: %d \n", num_twenties); 
    printf("Total Value: %.2f \n", num_twenties * 20.00); 
    printf("Remaining Change: %.2f \n", remaining_change); 
 
    
    return EXIT_SUCCESS;
}

// All pointers are ouput
void make_change(double change, double token_val,
                int *num_tokenp, double *leftp)
{
    *num_tokenp = floor(change / token_val);
    *leftp = change - *num_tokenp * token_val;
}