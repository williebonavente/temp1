#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int m = 10, n = 5;
    int *mp, *np;
    mp = &m;
    np = &n;
    *mp = *mp + *np;
    *np = *mp - *np;
    printf("m = %d, n = %d, *mp = %d, *np = %d\n", m, n, *mp, *np);

    return EXIT_SUCCESS;
}