
/*
*   Figure 7.4 shows a function that stores the same value (in_value) in all elements
*   of the array corresponding to its formal array parameter list.
*   The statement list[i] = in_value; stores in_value in element [i] its actual actual array argument
*/

/*
*   FIGURE 7.4 Function fill_array
*   Sets all elements of its array parameter to in_value
*   Pre: n and in_value are defined
*   Post: list[i] = in_value, for 0 <= 1 < n
*/

/*
void fill_array(int list[],     // output - list of n integers
                int n,          // input - number of list elements
                int in_value){  // input - initial value

    int i; // array subscript and loop control

    for (i = 0; i < n; ++i)
        list[i] = in_value;
                }
*/
/*
*   Arrays as input arguments
*   The qualifier const allows the compiler to mark as an error any attempt to change an
*   array element within a function e.g int get_max(const int List[])
*/

/*
*   FIGURE 7.6 Function to Find the Largest Element in an Array
*/

/*
*   Returns the largest of the first n values in array list
*   Pre: first n elements of array are defined and n > 0
*/

#include <stdio.h>

int get_max(const int List[], // input - list of n integers
            int n)      // input - number of list elements to examine
{
    int i;
    int cur_large;  // largest value so far

    // Initial array element is the largest so far

    cur_large = List[0];

    // Compare each remaining list element to the largest so far; save the larger

    for (i = 1; i < n; ++i){
        if (List[i] > cur_large){
            cur_large = List[i];
        }
    }

    return (cur_large);
}

int main(){

    int List[] = {1,2,3,4,5};
    printf("Max is %d", get_max(List, 5));
    
    return 0;
}

/*
*   Returning An Array
*   In c it is not legal for a function's return type to be an array, therefore
*   defining a function to return an array result requires the use
*   of an output parameter to send the result array back to the calling module
*
*   A function returning an array result depends on its caller to provide
*   an array variable into which the result can be stored
*
*   Function add_arrays in Figure 7.8 adds two arrays. The sum of arrays ar1 and ar2
*   is degined as arsum such that arsum[i] is equal to ar1[i] + ar2[i] for each
*   subscript[i]. The last parameter, n, specifies how many corresponding elements are summed
*
*/

/*
*   FIGURE 7.8 Function to Add Two Arrays
*   Adds corresponding elements of arrays ar1 and ar2, storing the result
*   in arsum. Processes first n elements only.
*   Pre: first n elements of ar1 and ar2 are defined. arsum's corresponding
*       actual argument has a declared size => n (n >= 0)
*/

void add_arrays(const double ar1[],     // input - 
                const double ar2[],     // arrays being added
                double arsum[],         // output - sum of corresponding elements of ar1 and ar2
                int n)                  // input - number of element pairs summed
{
    int i;

    // Adds corresponding elements of ar1 and ar2

    for (i = 0; i < n; ++i){
        arsum[i] = ar1[i] + ar2[i];
    }
}

/*
*   FIGURE 7.1 Function using a Sentinel Controlled Loop to Store Input Data in an Array
*
*   Gets data to place in dbl_arr until values of sentinel is encountered in the input
*   Returns number of values stored through dbl_sizep.
*   Stops input prematurely if there are more than dbl_max data values before
*   the sentinel or if invalid data is encountered.
*   Pre: sentinel and dbl_max are defined and dbl_max is the declared size
*       of dbl_arr
*/

void fill_to_sentinel(int dbl_max,      // input - declared size of dbl_arr
                    double sentinel,    // input - end of data value in input list
                    double dbl_arr[],     // output - array of data
                    int *dbl_sizep)     // output - number of data values stored in dbl_arr
{
    double data;
    int i, status;

    // Sentinel input loop
    i = 0;
    status = scanf("%lf", &data);
    while (status = 1 && data != sentinel && i < dbl_max){
        dbl_arr[i] = data;
        ++i;
        status = scanf("lf", &data);
    }

    // Issues error message on premature exit

    if(status != 1) {
        printf("\n*** Error in data format ***\n");
        printf("*** Using first %d data values ***\n", i);
    }
    else if (data != sentinel) {
        printf("\n***Error: too much data before sentinel ***\n");
        printf("*** Using first %d data values\n", i);
    }

    // Sends back size of used portion of array

    *dbl_sizep = i;

}

/*
*   FIGURE 7.12 Driver for Testing fill to sentinel
*
*   Driver to test fill_to_sentinel function
*/

#define A_SIZE 20
#define SENT -1.0

int main(){

    double arr[A_SIZE];
    int in_use;     // number of elements in use
    int i;

    fill_to_sentinel(A_SIZE, SENT, arr, &in_use);

    printf("List of data values\n");
    for (i = 0; i < in_use; ++i){
        printf("%13.3f\n", arr[i]);
    }

    return 0;
}

/*
*   FIGURE 7.14 Function That Searches for a Target Value in an Array
*   Returns the index of the target if it is present in the array, otherwise it returns -1
*
*   Searches for target item in first n elements of array arr
*   Returns index of target or NOT_FOUND
*   Pre: target and first n elements of array arr are defined and n >= 0
*/

#define NOT_FOUND -1    // Value returned by search function if target not found

int search(const int arr[],     // input - array to search
            int target,         // input - value searched for
            int n)              // input - number of elements to search
{
    int i,
    found = 0,      // whether or not target has been found
    where;          // index where target found or not_found

    /*  Compares each element to target */
    i = 0;
    while (!found && i < n){
        if (arr[i] == target){
            found = 1;
        }
        else{
            ++i;
        }
    }

    /*  Returns index of element matching target or NOT_FOUND   */
    if (found){
        where = i;
    }
    else{
        where = NOT_FOUND;
    }

    return (where);
}