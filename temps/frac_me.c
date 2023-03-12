#include <stdio.h>
#include <math.h>


void correct_fraction(int *, int *);

int main(void)
{
    int num, denom;

    num = 5;
    denom = -3;

    printf("Invalid Format >> %d/%d\n", num, denom); 
    correct_fraction(&num, &denom);

    return 0;
}

void correct_fraction(int *nump /*input*/, /*ouput*/ int *denomp)
{
    if ((*nump * *denomp) > 0)
        *nump = abs(*nump);

    else
        *nump = -abs(*nump);
    
    *denomp = abs(*denomp);

    printf("Valid Format >> %d/%d", *nump, *denomp); 
}