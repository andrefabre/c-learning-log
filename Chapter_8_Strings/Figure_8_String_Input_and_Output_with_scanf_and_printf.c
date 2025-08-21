
#include <stdio.h>

/*  Array of Strings
*   Because one string is an array of characters, an array of strings is a two-dimensional array of characters
*   in which each row is one string. The following are statements to declare an array to store up to 30 names,
*   each of which is less than 25 characters long.
*/

// Testing creating an array of strings and printing of string in the array to the screen //

/*
#define NUM_PEOPLE 30
#define NAME_LEN 25

int main(){

    char names[NUM_PEOPLE][NAME_LEN];

    char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Will this print all the months? : %s", month[2]);

return 0;

}

*/

/*  Figure 8.2 String Input/Output with scanf and printf
*   A brief main function performing string I/O with scanf and printf. In this program, the user is expected to type
*   in a string representing an academic department, and integer course code, a string abbreviation for the days of the
*   week the course meets, and an integer that gives the meeting time of the class.
*/

#define STRING_LENGTH 10

int main() {

    char dept[STRING_LENGTH];
    int course_num;
    char days[STRING_LENGTH];
    int time;

    printf("Enter the department code, course number, days and ");
    printf("time like this: \n> COSC 2060 MWF 1410\n");
    scanf("%s%d%s%d", dept, &course_num, days, &time);
    printf("%s %d meets %s at %d\n", dept, course_num, days, time);

    return 0;
}

// IMPORTANT - Scanf - When it scans a string, scanf skips leading whitespace characters such as blanks, newlines and tabs
// Starting with the first non-whitespace character, scanf copies the characters it encounters into successive memory
// cells of its character array arguement. When it comes to a whitespace character, scanning stops, and scanf places
// the null character at the end of the string in its array arguement.

