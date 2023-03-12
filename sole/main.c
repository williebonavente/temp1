/*
Estimate necessary solar for collecting area size for a particular  type of
construction in a given location
*/

#include <stdio.h>
#include <stdlib.h>

int days_in_month(int);
int nth_item(FILE *, int);

int main(void)
{
    // FILE INPUT
    int heat_deg_days, // average for coldest month
        solar_insol,   // average daily solar radiation per ft^2 for coldest month
        coldest_month, // coldest month: number in range 1...12
        
    // INPUT MANUALLY
        heating_req,   // BTU / degree day ft^2 requirement for given type of construction
        efficiency,    // % of solar insolation converted to usable heat
        collect_area,  // ft^2 needed to provide heat for coldest month
        
    //  
        ct,            // position in file
        status,        // file status variable
        next_hdd;      // one heating degree days value

    // Output
    double floor_space, // ft^2
        heat_loss,      // BTUs lost in coldest month

    // Placeholder
        energy_resrc;   // BTUs heat obtained from  1 ft^2

    FILE *hdd_file;   // average heating degree days for each of 12 months
    FILE *solar_file; // average solar insolation for each of 12 months

    // Get average heating degree days for coldest month from file
    hdd_file = fopen("hdd.txt", "r");
    fscanf(hdd_file, "%d", &heat_deg_days);
    coldest_month = 1;
    ct = 2;
    status = fscanf(hdd_file, "%d", &next_hdd);
    while (status == 1)
    {
        if (next_hdd > heat_deg_days)
        {
            heat_deg_days = next_hdd;
            coldest_month = ct;
        }
        ++ct;
        status = fscanf(hdd_file, "%d", &next_hdd);
    }
    fclose(hdd_file);

    // Get corresponding average daily solar insolation from other file
    solar_file = fopen("solar.txt", "r");
    solar_insol = nth_item(solar_file, coldest_month);
    fclose(solar_file);

    // Get from user specifics of this house
    printf("What is the approximate heating requirement (BTU / ");
    printf(" degree day ft^2)\nof this type of construction?\n=> ");
    scanf("%d", &heating_req);
    printf("What percent of solar insolation will be converted ");
    printf("to usable heat?\n =>");
    scanf("%d", &efficiency);
    printf("What is the floor space (ft^2)? \n=> ");
    scanf("%lf", &floor_space);

    // Project collecting area needed
    heat_loss = heating_req * floor_space * heat_deg_days;
    energy_resrc = efficiency * 0.01 * solar_insol * days_in_month(coldest_month);
    collect_area = (int)(heat_loss / energy_resrc + 0.5);

    // Display results
    printf("To replace heat loss of %.0f BTU in the ", heat_loss);
    printf("Coldest Month (month %d)\nwith available ", coldest_month);
    printf("solar insolation of %d BTU / ft^2 / day", solar_insol);
    printf(" and an\nefficiency of %d percent", efficiency);
    printf(" use a solar collecting area of %d ", collect_area);
    printf(" ft^2.\n");

    return 0;
}

/*
Given a month number (1 = Jan, 2 = Feb...... 12 = December)
return the number of days in the the month
(non-leap year).
Pre: 1 <= monthNumber <= 12
*/

int days_in_month(int month_number)
{
    int ans;

    switch (month_number)
    {
    case 2:
        ans = 28; // February
        break;

    case 4: // April
    case 6:
    case 9: // September
    case 11:
        ans = 30; // November
        break;

    default:
        ans = 31;
    }

    return ans;
}

/* Finds and returns the nth integer in a file.
Pre: data_file accesses a file of at least n integers (n >= 1).
*/

int nth_item(FILE *data_file, int n)
{
    int i, item;

    for (i = 1; i < n; ++i)
    {
        fscanf(data_file, "%d", &item);
    }

    return item;

    
}