#include <stdio.h>

void silly(int x);

int main(void)
{

    int x, y;

    x = 10;
    y = 11;
    silly(x);
    silly(y);

    return 0;
}

void silly(int x)
{
    int y;
    y = x + 2;
    x *= 2;
    printf("Value :%d\n", x);
}