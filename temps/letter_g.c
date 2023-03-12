#include <stdio.h>

int letter_grade(int points, char *gradep, double *just_missedp);

int main(void)
{

    int grade_inp;
    char letter;
    double next_high_grade;

    printf("Enter grade input >> ");
    scanf("%d", &grade_inp);

    letter_grade(grade_inp, &letter, &next_high_grade);

    printf("Letter Grade: %c \n", letter);

    if (grade_inp == 89 || grade_inp == 79 ||
        grade_inp == 69 || grade_inp == 59 ||
        grade_inp == 49 || grade_inp == 39)
    {
        printf("You just missed the higher grade %.0f", next_high_grade);
    }

    return 0;
}

int letter_grade(int points, char *gradep, double *just_missedp)
{
    if (points <= 100 && points >= 90)
    {
        *gradep = 'A';
    }

    else if (points <= 89 && points >= 80)
    {
        *gradep = 'B';
        *just_missedp = 90;
    }

    else if (points <= 79 && points >= 70)
    {
        *gradep = 'C';
        *just_missedp = 80;
    }
    else if (points <= 69 && points >= 60)
    {
        *gradep = 'D';
        *just_missedp = 70;
    }
    else if (points <= 59 && points >= 50)
    {
        *gradep = 'E';
        *just_missedp = 60;
    }
    else if (points <= 49 && points >= 40)
    {
        *gradep = 'F';
        *just_missedp = 50;
    }
    else if (points <= 39 && points >= 0)
    {
        *gradep = 'G';
        *just_missedp = 40;
    }

    return 0;
}