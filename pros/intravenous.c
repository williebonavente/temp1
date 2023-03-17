#include <stdio.h>
#include <math.h>

int get_problem();

void get_rate_drop_factor(float rate_ml_hr, float tubing_dp, float *dmp);
float fig_drops_min(float rate_ml_hr, float tubing_dp, float dmp);

void get_kg_rate_conc(float *rate_mg_kg_hr, float *kg, float *conc_mg_ml, float *ml_ph);

void get_units_conc(float rate_units_hr, float conc_units, float *ml_ph);

float by_weight(float rate_mg_kg_hr, float kg, float conc_mg_ml, float *ml_ph);

float fig_ml_hr(float *ml_ph);
float by_weight(float rate_mg_kg_hr, float kg, float conc_mg_ml, float *ml_ph);
float by_units(float rate_units_hr, float conc_units, float *ml_ph);

int main(void)
{

    int problem_sel; // problem selected

    char again; // again?

    float rate_ml_hr = 0, tubing_dp = 0, dmp = 0;
    float milliliter_per_hour = 0;
    float rate_mg_kg_hr = 0, kg = 0, conc_mg_ml = 0;
    float rate_units_hr = 0, conc_units = 0;

    do
    {
        problem_sel = get_problem();
        switch (problem_sel)
        {
        case 1:
            get_rate_drop_factor(rate_ml_hr, tubing_dp, &dmp);
            break;
        case 2:
            fig_ml_hr(&milliliter_per_hour);
            break;
        case 3:
            get_kg_rate_conc(&rate_mg_kg_hr, &kg, &conc_mg_ml, &milliliter_per_hour);
            break;
        case 4:
            get_units_conc(rate_units_hr, conc_units, &milliliter_per_hour);
            break;
        case 5:
            printf("\tQUIT!");
            break;
        }
        printf("\n\nAgain (Press Y): ");
        scanf_s(" %c", &again);
        printf(".\n");
    } while (again == 'Y' || again == 'y');

    return 0;
}

int get_problem()
{
    // For the problem selected
    int problem_sel;

    printf("Enter the number of the problem you wish to solve.\n");
    printf("\tGIVEN A MEDICAL ORDER IN\t\tCALCULATE RATE IN\n");
    printf("(1) ml/hr  & tubing drop factor         \tdrops / min\n");
    printf("(2) 1 L for n hr                        \tml / hr \n");
    printf("(3) mg/kg/hr & concentration in mg/ml   \tml / hr\n");
    printf("(4) units/hr & concentration in units/ml\tml/ hr\n");
    printf("(5) QUIT\n");

    printf("\n\tProblem >> ");
    scanf_s("%d", &problem_sel);

    return problem_sel;
}

void get_rate_drop_factor(float rate_ml_hr, float tubing_dp, float *dmp)
{
    printf("\tEnter rate in ml/hr => ");
    scanf_s("%f", &rate_ml_hr);
    printf("\tEnter tubing's drop factor (drops/ml) => ");
    scanf_s("%f", &tubing_dp);

    fig_drops_min(rate_ml_hr, tubing_dp, *dmp);
}

float fig_drops_min(float rate_ml_hr, float tubing_dp, float dmp)
{
    dmp = tubing_dp / 60 * rate_ml_hr;
    printf("\tThe drop rate per minute is %.0f.", ceil(dmp));
    return 0;
}

float fig_ml_hr(float *ml_ph)
{
    printf("\tEnter the number of hours => ");
    scanf_s("%f", ml_ph);
    float ans = 1000 / *ml_ph;
    printf("\tThe rate in milliliters per hours is %.0f.", ans);
    return 0;
}

void get_kg_rate_conc(float *rate_mg_kg_hr, float *kg, float *conc_mg_ml, float *ml_ph)
{
    printf("\tEnter rate in mg/kg/hr => ");
    scanf_s("%f", rate_mg_kg_hr);
    printf("\tEnter patient weight in kg => ");
    scanf_s("%f", kg);
    printf("\tEnter concentration in mg ml/ml => ");
    scanf_s("%f", conc_mg_ml);

    by_weight(*rate_mg_kg_hr, *kg, *conc_mg_ml, ml_ph);
}

float by_weight(float rate_mg_kg_hr, float kg, float conc_mg_ml, float *ml_ph)
{
    *ml_ph = rate_mg_kg_hr * kg * conc_mg_ml;
    float ansp = ceil(*ml_ph);
    printf("\tThe  rate in milliliters per hour is %.0f.", ansp);
    return 0;
}

void get_units_conc(float rate_units_hr, float conc_units, float *ml_ph)
{
    printf("\tEnter rate in units/hr => ");
    scanf_s("%f", &rate_units_hr);
    printf("\tEnter concentration => ");
    scanf_s("%f", &conc_units);

    by_units(rate_units_hr, conc_units, ml_ph);
}

float by_units(float rate_units_hr, float conc_units, float *ml_ph)
{
    *ml_ph = rate_units_hr / conc_units;
    printf("\tThe  rate in milliliters per hour is %.0f.", ceil(*ml_ph));
    return 0;
}