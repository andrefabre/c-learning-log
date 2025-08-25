/*
*   An array is a collecton of two or more adjacent memory cells, called 'array elements'. 
*   To set up a array in memory, we must declare both the name of the array and the 
*   the number of cells associated with it e.g. double x[8];
*/

#include <stdio.h>
#include <string.h>

int main(){

    double x[8] = {16.0, 12.0, 6.0, 8.0, 2.5, 12.0, 14.0, -54.5};
    int sum[] = {1, 2, 3, 4, 5};
    double new[4];
    int i; // loop counter
    int add_values[10] = {1, 2, 3, 4, 5};
    char three_strings[] = {"This is a long string"};

    // printf("%.1f\n", x[0]);

    // x[3] = 25.0;
    // printf("%.1f\n", x[3]);

    for (i = 0; i < 21; ++i){
        // printf("Count = %d and value = %.1f\n", i, x[i]);
        //new[i] = x[i + 1] * sum[i];
        //printf("Count = %d. X = %.1f, Sum = %d and value = %.1f\n", i, x[i + 1], sum[i], new[i]);
        
        printf("Index = %d , Value = %c\n", i, three_strings[i]);

    }

    //printf("%.1f", new);

    return 0;
}