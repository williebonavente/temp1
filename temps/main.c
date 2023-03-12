#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int a = 42; // Memory Address
    int b = 7;
    int c = 999;

    int *t = &a;
    int *u = NULL;

    printf("Part 1\n");

    printf("%d %d\n", a, *t);

    c = b; // c = 7
    u = t; // copy the address of t

    printf("Part 2\n");
    printf("%d %d\n", c, *u); // 7 42

    // New Value
    a = 8;
    b = 8;

    printf("Part 3\n");
    printf("%d %d %d %d\n", b, c, *t, *u); // 8 7 8 8

    *t = 123;
    printf("Part 4\n");
    printf("%d %d %d %d %d\n", a, b, c, *t, *u); //  123, 8, 7, 123, 123

    c = 555;
    *t = c;
    printf("%d %d %d %d %d\n", a, b, c, *t, *u); // 555, 8, 555, 555, 555

    


    return EXIT_SUCCESS;
}