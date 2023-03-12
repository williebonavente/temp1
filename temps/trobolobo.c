#include <stdio.h>
#include <stdlib.h>

void double_trouble(int *p, int y);
void trouble(int *x, int *y);

int main(void)
{

    int x, y;
    trouble(&x, &y);
    printf(" x = %d, y = %d\n", x, y);

    return EXIT_SUCCESS;
}

void double_trouble(int *p /* ouput */, int y /* input */)
{
    int x;
    x = 10;
    *p = 2 * x - y;
}

void trouble(int *x /*input/ouput*/, int *y /*input/ouput*/)
{
    double_trouble(x, 7);
    double_trouble(y, *x);
}
