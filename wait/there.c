#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE *inp;  // input of file
    FILE *outp; // output of file

    double item;

    int input_status;

    int counter = 0;
    float sum = 0; // Counter on how many items in the file
    float average;

    inp = fopen("input.txt", "r");
    outp = fopen("output.txt", "w");

    input_status = fscanf(inp, "%lf", &item);

    // Sorting the inputs

    while (input_status == 1)
    {
        counter ++;
        sum += item; // counter
        fprintf(outp, "%lf\n", item);
        input_status = fscanf(inp, "%lf", &item);
    }

    average = sum / counter;
    fprintf(outp, "\nTotal Number of Items: %i", counter);
    fprintf(outp, "\nSum of the items: %.2f", sum);
    fprintf(outp, "\nAverage of the  items: %.2f", average);
    // Close FiLE

    fclose(inp);
    fclose(outp);

    return EXIT_SUCCESS;
}