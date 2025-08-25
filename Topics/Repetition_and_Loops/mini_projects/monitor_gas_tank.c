/*
*   FIGURE 5.9 Program to Monitor Gasoline Storage Tank
*
*   Monitor gasoline supply in storage tank. Issue warning when supply falls below MIN_PCT % of tank capacity
*/

#include <stdio.h>

/*  constant macros */

#define CAPACITY        80000.0     // number of barrels tank can hold
#define MIN_PCT         10          // warn when supply falls below this percent of capacity
#define GALS_PER_BRL    42.0        // number of U.S. gallons in one barrel

/*  Function prototype  */

double monitor_gas(double min_supply, double start_supply);

int main(){

    double start_supply;    // input - initial supply in barrels
    double min_supply;      // minimum number of barrels left without warning
    double current;         // output - current supply in barrels

    /*  Computer minimum supply without warning */

    min_supply = MIN_PCT / 100.0 * CAPACITY;

    /*  Get initial supply  */

    printf("Number of barrels currently in tank> ");
    scanf("%lf", &start_supply);

    /*  Subtract amounts removed and display amount remaining   */

    current = monitor_gas(min_supply, start_supply);

    /* Issue warning    */

    printf("only %.2f barrels are left.\n\n", current);
    printf("****WARNING****\n");
    printf("Available supply is less than %d percent of tank's\n", MIN_PCT);
    printf("%.2f-barrel capacity.\n", CAPACITY);

    return 0;
}

/*
*   Computes and displays amount of gas remaining after each delivery
*   Pre: min_supply and start_supply are defined
*   Post: Returns the supply available (in barrels) after all permitted removals
*       The value returned is the first supply amount that is less than min_supply
*/

double monitor_gas(double min_supply, double start_supply){

    double remove_gals;  // amount of current delivery in barrels and gallons
    double remove_brls;
    double current;            // output - current supply in barrels

    for (current = start_supply; current > min_supply; current -= remove_brls){
        printf("%.2f barrels are available.\n\n", current);
        printf("Enter number of gallons removed> ");
        scanf("%lf", &remove_gals);
        remove_brls = remove_gals / GALS_PER_BRL;

        printf("After removal of %.2f gallons (%.2f barrels),\n", remove_gals, remove_brls);
    }

    return(current);
}