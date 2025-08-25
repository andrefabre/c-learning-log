
/*
*   FIGURE 5.4 Program to Compute Company Payroll
*   Compute the payroll for a company
*/

#include <stdio.h>

int main() {

    double total_pay;   // company payroll
    int count_emp;      // current employee
    int number_emp;     // number of employees
    double hours;       // hours worked
    double rate;        // hourly rate
    double pay;         // pay for this period

    //  Get number of employees

    printf("Enter number of employees> ");
    scanf("%d", &number_emp);

    //  Compute each employees pay and add it to the payroll

    total_pay = 0;
    count_emp = 0;
    while (count_emp < number_emp) {
        printf("Hours> ");
        scanf("%lf", &hours);
        printf("Rate> ");
        scanf("%lf", &rate);
        pay = hours * rate;
        printf("Pay is $%6.2f\n\n", pay);
        total_pay += pay;   // Add next pay
        count_emp += 1;
    }

    printf("All employees processed\n");
    printf("Total payroll is $%8.2f\n", total_pay);

    return 0;
}

/*
*   Using a for Statement in a Counting Loop
*/

/*  Process payroll for all employees
*/

total_pay = 0.0;
for (count_emp = 0; count_emp < number_emp; count_emp += 1)
{
    printf("Hours> ");
    scanf("%lf", &hours);
    printf("Rate> ");
    scanf("%lf", &rate);
    pay = hours * rate;
    printf("Pay is $%6.2f\n\n", pay);
    total_pay += pay;   // Add next pay
}