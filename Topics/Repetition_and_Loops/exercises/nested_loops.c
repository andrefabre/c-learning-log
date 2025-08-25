/*
*   FIGURE 5.12 Program to Process Bald Eagle Sightings for a Year
*
*   Tally by onth the bald eagle sightings for the year. Each month's
*   sightings are terminated by the sentinel zero.
*/

#include <stdio.h>

#define SENTINEL 0
#define NUM_MONTHS  12

int main() {

    int month;      // number of month being processed
    int mem_sight;  // one member's sightings for this month
    int sightings;  // total sightings so far for this month

    printf("BALD EAGLE SIGHTINGS\n");
    for (month = 1; month <= NUM_MONTHS; ++month){
        sightings = 0;
        scanf("%d", &mem_sight);
        while (mem_sight != SENTINEL)
            if (mem_sight >= 0) {
                sightings += mem_sight;
            }
            else {
                printf("Warning, negative count %d ignored\n", mem_sight);
            }
            scanf("%d", &mem_sight);

    }

    printf(" month %2d: %2d\n", month, sightings);

    return 0;
}


/*
*   FIGURE 5.13 Nested Counting Loop Program
*
*   Illustrates a pair of nested counting loops
*
*/

#include <stdio.h>

int main(){

    int i, j; // loop control variables

    printf("      i   j\n"); // prints column labels

    for (i = 1; i < 4; ++i) {               // heading of outer loop
        printf("Outer %6d\n", i);
        for (j = 0; j < i; ++j){            // heading of inner loop
            printf("Inner %9d\n", j);
        } // end of inner loop
    }   // end of outer loop

    return 0;
}