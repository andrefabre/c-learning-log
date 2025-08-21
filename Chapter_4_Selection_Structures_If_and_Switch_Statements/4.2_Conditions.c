/*
*   FIGURE 4.5 Program Using an IF statement for Selection
*/

#include <stdio.h>

int main() {

    int pulse; // resting pulse rtate for 10 secs
    int rest_heart_rate; // resting heart rate for 1 minute

    // Enter your resting pulse rate

    printf("Take your resting pulse for 10 secs. \n");
    printf("Enter your pulse rate and press return> ");
    scanf("%d", &pulse);

    // Calculate resting heart rate for 1 minute

    rest_heart_rate = pulse * 6;
    printf("Your resting heart rate is %d\n", rest_heart_rate);

    if (rest_heart_rate > 75)
        printf("Keep up your exercise program\n");
    else
        printf("Your heart is in doing well!\n");

    return 0;

}