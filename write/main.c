#include <stdio.h>
#include <stdlib.h>

int main (void) {
    
    FILE *inp; // pointer to input file
    FILE *outp; // pointer to output file

    double item;
    int input_status; // status value returned by fscanf

    inp = fopen("input.txt", "r");
    outp = fopen("output.txt", "w");
    
    // Read each item, format it, and write it
    input_status = fscanf(inp, "%lf", &item);
    
    while (input_status == 1)
    {
        fprintf(outp, "%.2f\n", item);
        input_status = fscanf(inp, "%lf\n", &item);
    }

    // Close the files
    fclose(inp);
    fclose(outp);
    
    return EXIT_SUCCESS;
}