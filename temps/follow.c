#include <stdio.h>
#include <stdlib.h>

int onef(int *dat, int *oupt1p, int *out2p);
int twof(int indat, int *result1p, int *result2p);

int main(int argc, char *argv[])
{

    return EXIT_SUCCESS;
}

int onef(int *dat, int *out1p, int *out2p)
{
    // Declaring integer local variable
    int tmp;

    /* call the function of twof() is declared
    Passing input argument as dat
    Passing output argument as tmp and out2p
    */

    twof(dat, &tmp, out2p);
}



int twof(int indat, int *result1p, int *result2p)
{

}