/*
*   FIGURE 3.23 Function Scale
*   Multiplies its first argument by the power of 10 specified by its second argument
*   Pre: x and n are define and math.h is included
*/

double scale (double x, int n) {

    double scale_factor; // local variable
    scale_factor = pow(10, n);

    return (x * scale_factor);
}

/*
*   FIGURE 3.24 Testing Function Scale
*
*   Tests function scale
*/

#include <stdio.h>
#include <math.h>

// Function Prototype //

double scale(double x, int n);

int main(){

    double num_1;
    int num_2;

    // Get values for num_1 and num_2

    printf("Enter a real number> ");
    scanf("%lf", &num_1);
    printf("Enter an integer> ");
    scanf("%d", &num_2);

    // Call scale and display result

    printf("Result of call to function scale is %f\n", scale(num_1, num_2));

    return 0;
}
