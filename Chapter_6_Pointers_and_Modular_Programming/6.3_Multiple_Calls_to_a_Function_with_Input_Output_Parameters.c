/*
*   Demonstrates the use of a single parameter to both to bring a data value into a function
*   and to carry a result function out of the function
*
*   FIGURE 6.7 Program to sort three numbers
*/

#include <stdio.h>

void order(double *smp, double *lgp);

int main(){

    double num1, num2, num3;    // three numbers to put in order

    // Gets test data
    printf("Enter the three numbers separated by blanks> ");
    scanf("%lf%lf%lf", &num1, &num2, &num3);

    // Orders these numbers

    order(&num1, &num2);
    order(&num1, &num3);
    order(&num2, &num3);

    // Displays results
    printf("The numbers in ascending order are: %.2f %.2f %.2f\n", num1, num2, num3);

    return 0;
}

/*
*   Arrange arguments in ascending order
*   Pre: smp and lgp are addresses of defined type double variables
*   Post: variable pointed to by smp contains the smaller of the type
*       double values; variable pointed to by lgp contains the larger
*/

void order(double *smp, double *lgp){

    double temp;        // temporary variable to hold one number during swap

    // Compares the values pointed to by smp and lgp and switches if necessary

    if (*smp > *lgp) {
        temp = *smp;
        *smp = *lgp;
        *lgp = temp;
    }
}