/*  String library functions strcat and strncat modify their first argument by adding all
*   or part of their second string arguement at the end of the first argument.
*   Both functions assume that sufficient space is allocated for the first argument to allow
*   addition of the extra characters*/

/*
#include <stdio.h>
#include <string.h>

#define STRSIZE 20

int main(){

    char s1[STRSIZE] = "Jupiter ";
    char s2[STRSIZE] = "Symphony";

    printf("%d\n", strlen(s1));
    printf("%d\n", strlen(strcat(s1, s2)));
    printf("%s\n", s1);

    return 0;
}

*/

// FIGURE 8.14 Two orderings of one list using an array of pointers

/*
*   Maintains two orderings of a list of applicants: the original ordering of the data
*   and the alphabetical ordering accessed through an array of pointers
*/

#include <stdio.h>
#include <string.h>

#define STRSIZE 30  // Maximum string length
#define MAXAPP 50   // Maximum number of applicantions accepted

int alpha_first(char *list[], int min_sub, int max_sub);
void select_sort_str(char *list[], int n);

int main(){

    char applicants[MAXAPP][STRSIZE];   // List of applicants in the order which they applied
    char *alpha[MAXAPP];                // List of pointers to applicants
    int num_app;                        // Actual number of applicants
    int i;
    char one_char;

    // Gets applicant list

    printf("Enter the number of applicants (0..%d)\n", MAXAPP);
    scanf("%d", &num_app);
    do // skips rest of line after number
        scanf("%c", &one_char);
    while(one_char != '\n');

    printf("Enter names of applicants on separate line of less than\n");
    printf(" 30 characters in the order in which they applied\n");

    for(i = 0; i < num_app; ++i)
        gets(applicants[i]);
    
    // Fills array of pointers and sorts

    for (i = 0; i < num_app; ++i)
        alpha[i] = applicants[i]; // copies ONLY address

    select_sort_str(alpha, num_app); // Call function with alpha array and number of applications are args

    //  Displays both lists

    printf("\n\n%-30s%5c%-30s\n\n", "Application Order", ' ', "Alphabetical Order");

    for (i = 0; i < num_app; ++i)
        printf("%-30s%5c%-30s\n", applicants[i], ' ', alpha[i]);

    return 0;
}

/*  Finds the index of the string that comes first alphabetically in elements min_sub..max_sub of list
*   Pre: list[min_sub] through list[max_sub] are of uniform case;
*       max_sub >= min_sub
*   
*/

int alpha_first(char *list[], //input - array of pointers to strings
        int min_sub, // input - minimum and maximum subscripts
        int max_sub) // of portion of lists to consider
{   
    int first, i;

    first = min_sub;

    for (i = min_sub + 1; i <= max_sub; ++i)
        if (strcmp(list[i], list[first]) < 0)
            first = i;
    
    return (first);

}

/*  Orderrs the pointers in array listso they access strings in alphabetical order
*   Pre: first n elements of list reference strings of uniform case;
*        n >= 0
*/

void select_sort_str(char *list[], // input/output - array of points being ordered to access strings alphabetically
                        int n)     // input - number of elements to sort
{
    int fill;   // index of element to contain next string in order
    int index_of_min;   // index of next string in order
    char *temp;

    for (fill = 0; fill < n - 1; ++fill) {
        index_of_min = alpha_first(list, fill, n - 1);

        if (index_of_min != fill) {
            temp = list[index_of_min];
            list[index_of_min] = list[fill];
            list[fill] = temp;
        }
    }
}


