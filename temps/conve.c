#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b, int *cp);

int main(void)
{

    int x, y, z;
    x = 7; y = 2;
    printf("    x   y   z\n\n");
    sum(x, y, &z);
    sum(y, x, &z);
    sum(z, y, &x);
    sum(z, z, &x);
    sum(y, y, &y);

    return EXIT_SUCCESS;
}

int sum(int a, int b, int *cp)
{
    *cp = a + b;
    printf("%4d%4d%4d\n", a, b, *cp);
    
    return 0;
}