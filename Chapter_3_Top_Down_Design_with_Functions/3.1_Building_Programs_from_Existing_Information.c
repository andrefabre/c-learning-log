/*
*   CASE STUDY: Finding the Area and Circumference of a Circle
*   Problem: Get the radius of a circle. Compute and display the circle's area and circumference
*/

/*
*   FIGURE 3.2 Outline of Program Circle
*   Calculates and displays the area and circumference of a circle
*/

#include <stdio.h>
#define PI 3.14159

int main() {

    double radius;      // input - radius of a circle
    double area;        // output - area of a circle
    double circum;      // output - circumference

    /*  Get the circle radius    */
    printf("Enter radius> ");
    scanf("%lf", &radius);

    /*  Calculate the area  */
        /* Assign PI * radius * radius to area */
    area = PI * radius * radius;

    /* Calculate the circumference  */
        /* Assign 2 * PI * radius to circum */
    circum = 2 * PI * radius;

    /*  Display the area and circumference */
    printf("The area is: %.4f\n", area);
    printf("The circumference is: %.4f\n", circum);

    return 0;
}
