/*
*   Sentinel Controlled Loops
*   
*   Sentinel Loop (example)
*       1. Initialise sum to zero
*       2. Get first score
*       3. while score is not the sentinel
*           4. Add score to sum
*           5. Get next score
*/

/*-----------------------------------------------------*/

/*  FIGURE 5.10 Sentinel Controlled While Loop
*   
*   Compute the sum of a list of exam scores
*/

#include <stdio.h>

#define SENTINEL -99

int main(){

    int sum = 0;        // Sum of scores input so far
    int score;

    // Accumulate sum of all scores

    printf("Enter first score or (%d to quit)> ", SENTINEL);
    scanf("%d", &score);
    while (score != SENTINEL){
        sum += score;
        printf("Enter next score or (%d to quit)> ", SENTINEL);
        scanf("%d", &score);
    }

    printf("The sum of all exam scores is %d.\n", sum);

    return 0;
}

/*  Using a for Statement to Implement a Sentinel Loop
*
*   The for statement form of the while loop for Figure 5.10 above is as follows
*/

printf("Enter the first score or (%d to quit)> ", SENTINEL);
for (scanf("%d", &score); score != SENTINEL; scanf("%d", &score)){
    sum += score;
    printf("Enter next score (%d to quit)> ", SENTINEL);
}