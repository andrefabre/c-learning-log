/*
*   CASE STUDY: Computing the Weight of a batch of Flat Washers
*/

/*  
*   FIGURE 3.5 Flat Washer Program
*/

#include <stdio.h>
#define PI 3.14159

int main() {

    double hole_diameter;    // input - diameter of hole
    double edge_diameter;    // input - diameter of outer edge
    double thickness;        // input - thickness of washer
    double density;          // input - density of material used
    double quantity;         // input - number of washers made
    double weight;           // output - weight of washer batch
    double hole_radius;      // radius of hole
    double edge_radius;      // radius of outer edge
    double rim_area;         // area of rim
    double unit_weight;      // weight of 1 washer

    /*  Get the inner diameter, outer diameter and thickness    */

    printf("Inner diameter in centimeters> ");
    scanf("%lf", &hole_diameter);
    printf("Outer diameter in centimeters> ");
    scanf("%lf", &edge_diameter);
    printf("Thickness in centimeters> ");
    scanf("%lf", &thickness);

    /*  Get the material density and quantity manufactured  */

    printf("Material density in grams per cubic centimeter> ");
    scanf("%lf", &density);
    printf("Quantity in batch> ");
    scanf("%lf", &quantity);

    /*  Computer the rim area   */

    hole_radius = hole_diameter / 2.0;
    edge_radius = edge_diameter / 2.0;
    rim_area = PI * edge_radius * edge_radius - PI * hole_radius * hole_radius;

    /*  Compare the weight of a flat washer */

    unit_weight = rim_area * thickness * density;

    /*  Compute the weight og the batch of washers  */

    weight = unit_weight * quantity;

    /*  Display the wight of the batch of washers   */

    printf("The expected weight of the batch is %.2f", weight);
    printf(" grams.\n");

    return 0;
}