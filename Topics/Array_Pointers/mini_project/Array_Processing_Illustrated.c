/*
*   CASE STUDY: Summary of Hospital Revenue
*
*   Data Requirements:
*   New Types
*   quarter_t   {fall, winter, spring, summer}
*   unit_t      {emerg, medic, oncol, ortho, psych}
*
*   Problem Constants
*   NUM_UNITS 5
*   NUM_QUARTERS 4
*
*   Problem Inputs
*   Revenue transactions file
*   double revenue[NUM_UNITS][NUM_QUARTERS] // revenue data array
*
*   Problem Outputs
*   double unit_totals[NUM_UNITS];  // Totals for each row of table
*   double quarter_totals[NUM_UNITS]; // Totals for each column
*
*   Design:
*       1. Scan revenue data, posting by unit and quarter, and returning a value to show success or failure
*       2. If the data scan proceeded without error
*           3. Compute unit totals(row sums)
*           4. Compute quarterly totals (column sums)
*           5. Display the revenue table along with the row and column sums
*
*   FIGURE 7.24 Hospital Revenue Summary Main Function
*   Scans revenue figures for one year and stores them in a table organised
*   by unit and quarter. Displays the tablet and the annual totals for each unit
*   and the revenue totals for each quarter
*/

#include <stdio.h>

#define REVENUE_FILE "revenue.txt"  // Name of revenue data file
#define NUM_UNITS 5
#define NUM_QUARTERS 4

typedef enum{
    summer, fall, winter, spring        // Index 0 = summer, 1 = fall, 2 = winter, 3 = spring
} quarter_t;

typedef enum{
    emerg, medic, oncol, ortho, psych   // Index: 0 = emerg, 1 = medic, 2 = oncol, 3 = ortho, 4 = psych
} unit_t;

int scan_table(double revenue[][NUM_QUARTERS], int num_rows);
void sum_rows(double row_sum[], double revenue[][NUM_QUARTERS], int num_rows);
void sum_columns(double col_sum[], double revenue[][NUM_QUARTERS], int num_rows);
void display_table(double revenue[][NUM_QUARTERS], const double unit_totals[], const double quarter_totals[], int num_rows);

// Insert function protypes for any helper functions

int main(){

    double revenue[NUM_UNITS][NUM_QUARTERS]; // table of revenue
    double unit_totals[NUM_UNITS];  // row totals
    double quarter_totals[NUM_QUARTERS]; // column totals
    int status;

    status = scan_table(revenue, NUM_UNITS);
    if(status == 1) {
        sum_rows(unit_totals, revenue, NUM_UNITS);
        sum_columns(quarter_totals, revenue, NUM_UNITS);
        display_table(revenue, unit_totals, quarter_totals, NUM_UNITS);
    }

    return 0;
}   

/*
*   Scans the revenue data from REVENUE_FILE and computes and stores the
*   revenue results in the revenue table. Flags out of range data and data format errors
*   Post: each entry of revenue represents the revenue total for a 
*       particular unit and quarter.
*       Returns 1 for successful table scan, 0 for error in scan.
*   Calls: initialise to initialise table to all zeros
*/

int scan_table(double revenue[][NUM_QUARTERS],      // output
                int num_rows)                        // input
{
    double trans_amount;        // transaction amount
    int trans_unit;             // unit number
    int quarter;                // revenue quarter
    FILE *revenue_filep;        // file pointer to revenue file
    int valid_table = 1;        // data valid so far
    int status;                 // input status
    char ch;                    // one character in a bad line

    //  Initialise table to all zeros

    initialise(revenue, num_rows, 0.0);

    // Scan and store the valid revenue data

    revenue_filep = fopen(REVENUE_FILE, "r");
    for (status = fscanf(revenue_filep, "%d%d$lf", &trans_unit, &quarter, &trans_amount);
                  status == 3 && valid_table;
                status = fscanf(revenue_filep, "%d%d%lf", &trans_amount, &quarter, &trans_amount)) {
                    if (summer <= quarter && quarter <= spring && trans_unit >= 0 && trans_unit < num_rows)
                    revenue[trans_unit][quarter] += trans_amount;
                    else{
                        printf("Invalid unit or quarter -- \n");
                        printf("  unit is ");
                        display_unit(trans_unit);
                        printf(", quarter is ");
                        display_quarter(quarter);
                        printf("\n\n");
                        valid_table = 0;
                    }
                }
    
    if (!valid_table) {         // error already processes
        status = 0;
    } else if (status == EOF){  // end of data without error
        status = 1;
    } else  {                   // data format error
        printf("Error in revenue data format. Revise data.\n");
        printf("Error here >>> ");
        for (status = fscanf(revenue_filep, "%c", &ch);
             status == 1 && ch != '\n';
             status = fscan(revenue_filep, "%c", &ch))
            printf("%c", ch);
        printf(" <<<\n");
        status = 0;
    }

    return (status);

}

/*
*   Stores value in all elements of revenue.
*   Pre: value is defined and num_rows it the number of rows in revnue.
*   Post: all elements of revenue have the desired value
*/

void initialise(double revenue[][NUM_QUARTERS],     // output
                int num_rows,                       // input
                double value)                       // input
{
    int row;
    quarter_t quarter;

    for (row = 0; row < num_rows; ++row)
        for (quarter = summer; quarter <= spring; ++quarter)
        revenue[row][quarter] = value;
    
}

/*
*   FIGURE 7.26 Function display_table and Helper Functions display_quarter and whole_thousands
*
*   Displays the revenue table data (rounded to whole thousands) in table
*   form along with the row and column sums (also rounded)
*   Pre: revenue, unit_totals, quarter_totals, and num_rows are defined.
*   Post: Values stored in the three arrays are displayed rounded to whole thousands
*/

void display_table(double revenue[][NUM_QUARTERS],      // input
                    const double unit_totals[],          // input
                    const double quarter_totals[],      // input
                    int num_rows)                       // input
{
    unit_t unit;
    quarter_t quarter;

    //  Display heading
    printf("%34cREVENUE SUMMARY\nn34c---------------\n\n", ' ', ' ');
    printf("%4s%11c", "Unit", ' ');
    for (quarter = summer; quarter <= spring; ++quarter){
        display_quarter(quarter);
        printf("%8c", ' ');
    }
    printf("TOTAL*\n");
    printf("----------------------------------------");
    printf("----------------------------------------\n");

    //  Display Table

    for (unit = emerg; unit <= psych; ++unit){
        display_unit(unit);
        printf(" ");
        for (quarter = summer; quarter <= spring; ++quarter){
            printf("%14.2f", revenue[unit][quarter]);
        printf("%13d\n", whole_thousands(unit_totals[unit]));
        }
    }
    printf("----------------------------------------");
    printf("----------------------------------------\n");
    printf("TOTALS*");
    for (quarter = summer; quarter <= spring; ++quarter){
        printf("%14d", wholethousands(quarter_totals[quarter]));
    }
    printf("\n\n*in thousands of dollars\n");
}

/*
*   Displays an enumeration of type quarter_t
*/

void display_quarter(quarter_t quarter){

    switch(quarter){
    case summer:
        printf("Summer");
        break;
    case fall:
        printf("Fall");
        break;
    case winter:
        printf("Winter");
        break;
    case spring:
        printf("Spring");
        break;
    default:
        printf("Invalid quarter %d", quarter);
        
    }
}

/*
*   Displays an enumeration of type unit_c
*/

void display_unit(unit_t unit){

    switch(unit){
    case emerg:
        printf("Emerg");
        break;
    case medic:
        printf("Medic");
        break;
    case oncol:
        printf("Oncol");
        break;
    case ortho:
        printf("Ortho");
        break;
    case psych:
        printf("Psych");
        break;
    default:
        printf("Invalid unit %d", unit);
    }
}

/*
*   Return how many thousands are in number
*/

int wholethousands(double number){
    return (int) ((number + 500)/1000.0);
}