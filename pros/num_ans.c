#include <stdio.h>

int is_multiples(FILE *, int );
int eve_odd(FILE *, int);
int is_prime(FILE *, int);

int main(void)
{
// todo : format the file
    FILE *input;
    FILE *output;

    int status; // as whole file
    int item;   // each item in the file

    int sum =0; // sum of all the numbers
    int counter = 0; // counter for all items
    input = fopen("texts\\numin.txt", "r");
    output = fopen("texts\\numout.txt", "w");

    status = fscanf_s(input, "%d", &item);

    while (status == 1)
    {
        counter += 1;
        sum += item;
        fprintf(output,"%d ", item);
        fprintf(output,"%s ", "is ");
        is_multiples(output, item);
        fprintf(output,"%s ", "and ");
        eve_odd(output, counter);
        status = fscanf_s(input, "%d", &item);
    }
    fprintf(output,"Number of items: %i\n", counter);
    fprintf(output,"The sum is %d", sum);

    fclose(input);
    fclose(output);

    return 0;
}

int is_multiples(FILE *input, int item)
{

    if (item % 7 == 0)
    {
        fprintf(input, "%s", "multiples of 7 ");
    }

    else if (item % 11 == 0)
    {
        fprintf(input, "%s", "multiples of 11 ");
    }
    else if (item % 13 == 0)
    {
        fprintf(input, "%s", "multiples of 13 ");
    }

    else
    {
        fprintf(input, "%s", "The value is neither multiples of 7, 11 and 13.\n");
    }

    return item;
}

int eve_odd(FILE *input, int item)
{

    if (item % 2 == 0)
    {
        fprintf(input, "%s", "even Number.\n");
    }

    else if (item % 2 != 0)
    {
        fprintf(input, "%s", "odd Number.\n");
    }

  

    return item;
}

// int is_prime(FILE *input)
// {
// }