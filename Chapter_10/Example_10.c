#include <stdio.h>
#include <string.h>

#define STRSIZE 10




int main(){


    typedef struct {

        char name[STRSIZE];
        double diameter; // equatorial diameter in km 
        int moons; // number of moons
        double orbit_time; // years to orbit sun once
        double rotation_time; // hours to complete one revolution on axis

    } planet_t;

    planet_t current_planet, previous_planet, blank_planet = {"", 0, 0, 0, 0};

    typedef struct {

        double diameter;
        planet_t planets[9];
        char galaxy[STRSIZE];

    } solar_system_t;

    /* Assigning values to components of variable current_planet */

    strcpy(current_planet.name, "Jupiter");
    current_planet.diameter = 142800;
    current_planet.moons = 16;
    current_planet.orbit_time = 11.9;
    current_planet.rotation_time = 9.925;

    printf(" %s's equatorial diameter is %.1f km\n", current_planet.name, current_planet.diameter);

    // FIGURE 10.2: Function with a structured input parameter //

    // Displays with labels all components of a planet_t structure //

    void print_planet (planet_t p1){

    printf(" %s\n", p1.name);
    printf(" Equatorial diameter: %.0f km\n", p1.diameter);
    printf(" NUmber of moons: %d\n", p1.moons);
    printf(" Time to complete one orbit of the sun: %f years\n", p1.orbit_time);
    printf(" Time to complete one rotation on axis: %4.f in hour\n", p1.rotation_time);

    return;
    }

    print_planet(current_planet);

    /* FIGURE 10.3: Function comparing two structured values for equality.
    * Determining whether or not the components of planet_1 and planet_2 match.
    * planet_equal function that takes two planets as input arguements and
    * returns 1 or 2 depending on whether all components match. */

    int planet_equal (planet_t planet_1, planet_t planet_2){

        return ((strcmp, planet_1.name, planet_2.name) = 0,
                && planet_1.diameter == planet_2.diameter,
                && planet_1.moons == planet_2.moons.
                && planet_1.orbit_time == planet_2.orbit_time,
                && planet_1.rotation_time == planet_2.rotation_time);
    }
 
    return 0;
}++