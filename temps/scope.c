#include <stdio.h>
#include <stdlib.h>

void scan_fraction(int *nump, int *denomp);

int main(void)
{

    return EXIT_SUCCESS;
}

void scan_fraction(int *nump, int *denomp)
{

    char slash;
    int status;

    int error;
    char discard;

    do
    {
        // No Error detected yet
        error = 0;

        // Get fraction from the user
        printf("Enter a common fraction as two integers separated ");
        printf("by a slash > ");
        status = scanf("%d%c%d", nump, &slash, denomp);

        // Validate the fraction
        if (status < 3)
        {
            error = 1;
            printf("Invalid-please read directions carefully \n");
        }

        else if (slash != '/')
        {
            error = 1;
            printf("Invalid-separate numerator and denominator ");
            printf("by a slash (/)\n");
        }

        else if (*denomp == 0)
        {
            printf("Invalid-denominator must be positive\n");
        }

        // Discard extra input characters
        do
        {
            scanf("%c", &discard);
        } while (discard != '\n');

    } while (error);
}