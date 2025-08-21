/*
*   Parallel arrays: two or more arrays with the same number of elements used for storing
*   related information about a collection of data objects
*/

/*
*   Figure 7.17 shows a simple program that reads data into these two parallel arrays
*   and displays the information stored. We show just the output for the first two elements of each array.
*/

/*
*   FIGURE 7.17 Student Data in Parallel Arrays
*   Read data for parallel arrays and echo stored data
*/

#include <stdio.h>
// #define NUM_STUDENTS 50

// int main(){

//     int id[NUM_STUDENTS];
//     double gpa[NUM_STUDENTS];
//     int i;

//     for (i = 0; i < NUM_STUDENTS; ++i){
//         printf("Enter the id and gpa for student %d: ", i);
//         scanf("%d%lf", &id[i], &gpa[i]);
//         printf("%d  %4.2f\n", id[i], gpa[i]);
//     }

//     return 0;
// }

/*
*   Enumerated Types
*   ANSI C allows you to associate a numeric code with each category by creating
*   an enumerated type that has its own list of meaningful values
*
*   FIGURE 7.18 Enumerated Type for Budget Expenses
*   Program demonstrating the use of an enumerated type
*/


typedef enum
    {entertainment, rent, utilities, food, clothing, automobile, insurance, miscellaneous
    } expense_t;

void print_expense(expense_t expense_kind);

int  main(){

    expense_t expense_kind;

    printf("Enter an expense code between 0 and 7>> ");
    scanf("%d", &expense_kind);
    printf("Expense code represents ");
    print_expense(expense_kind);
    printf(".\n");

    return 0;
}

/*
*   Display string corresponding to a value of type expense
*/

void print_expense(expense_t expense_kind){

    switch (expense_kind) {
        case entertainment:
            printf("entertainment");
            break;
        case rent:
            printf("rent");
            break;
        case utilities:
            printf("utilities");
            break;
        case food:
            printf("food");
            break;
        case automobile:
            printf("automobile");
            break;
        case insurance:
            printf("insurance");
            break;
        case miscellaneous:
            printf("miscellaneous");
            break;
        default:
            printf("\n*** INVALIDE CODE ***\n");
    }
}
