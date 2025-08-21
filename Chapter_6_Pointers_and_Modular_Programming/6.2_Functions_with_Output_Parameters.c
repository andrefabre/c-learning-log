/*
*   FIGURE 6.3 Function Separate
*
*   Separates a number into three parts: a sign(+, - or blank)
*   a whole number magnitude, and a fractional part. 
*/

void separate(double num,       // input - value to be split
                char *signp,    // output - sign of num
                int *wholep,    // output - whole number of magnitude num
                double *fracp) // output - fractional part of num
{
    double magnitude;   // local variable - magnitude of num

    // Determines sign of num
    if (num < 0){
        *signp = '-';
    }
    else if (num == 0){
        *signp = ' ';
    }
    else {
        *signp = '+';
    }
    
    // Finds magnitude of num (its absolute value) and separates it into whole and fractional parts

    magnitude = fabs(num);
    *wholep = floor(magnitude);
    *fracp = magnitude - *wholep;
}

/*
*   FIGURE 6.5 Program the calls a function with Output Arguments
*
*   Demonstrates the use of a function with input and output parameters
*/

#include <stdio.h>
#include <math.h>

void separate(double num, char *signp, int *wholep, double *fracp);

int main(){

    double value;       // input - number to analyse
    char sn;            // output - sign of value
    int whl;            // output - whole number magnitude of value
    double frac;        // output - fractional part of value

    // Gets data

    printf("Enter a value to analyse> ");
    scanf("%lf", &value);

    // Separate date value into three parts

    separate(value, &sn, &whl, &frac);

    // Prints results
    printf("Parts of %.4f\n sign: %c\n", value, sn);
    printf(" whole number magnitude: %d\n", whl);
    prtinf(" fractional part: %.4f\n", frac);

    return 0;
}

/*
*   Separates a number into three parts: a sign (+, -, or blank), a whole number magnitude
*   and a fractional part. 
*   Pre: num is defined; signp, wholep, and fracp contain addresses of memory cells
*       where results are to be stored
*   Post: function results are stored in cells pointed to by signp, wholep and fracp
*/

void separate(double num,       // input - value to be split
                char *signp,    // output - sign of num
                int *wholep,    // output - whole number of magnitude num
                double *fracp) // output - fractional part of num
{
    double magnitude;   // local variable - magnitude of num

    // Determines sign of num
    if (num < 0){
        *signp = '-';
    }
    else if (num == 0){
        *signp = ' ';
    }
    else {
        *signp = '+';
    }
    
    // Finds magnitude of num (its absolute value) and separates it into whole and fractional parts

    magnitude = fabs(num);
    *wholep = floor(magnitude);
    *fracp = magnitude - *wholep;
} 
