 #include <stdio.h>
 #include <string.h>


 /* Practicing how to use strcpy and strncpy to test understanding */


 int main(){

    char last [20], first [20], middle [20];
    char pres[20] = "Adams, John Quincy";

    char *first_name = strncpy(first, &pres[7], 4); // Start from 7 and to 4 characters
    first[4] = '\0';

    char *middle_name = strcpy(middle, &pres[12]); // Start from 12th character
    middle[12] = '\0';

    char *last_name = strncpy(last, pres, 5); // start from first character to 5th character
    last[5] = '\0';

    printf("First name is: %s\nMiddle name is: %s\nLast name is: %s", first_name, middle_name, last_name);

    char *first_and_middle = strcat(first, "Quincy");

    printf("\nString cat function %s", first_and_middle);

    return 0;

 }


/*  Figure 8.7 breaks compounds into their elemental components, assuming that each element name
*   begins with a capital letter and that our implementation is using the ASCII character set.
*   For example, this program would break "NaCl" into "Na" and "Cl". The if statement in the for
*   loop tests whether the character at position next is uppercase. If so, strncpy copies into
*   elem all characters from the last capital (at position first) up to (but not including)
*   the capital letter at position next*/

/*  Program using strncpy and strcpy Functions to Separate Compounds into Elemental Components  */

// //  Displays each elemental component of a compound //

//  #include <stdio.h>
//  #include <string.h>

// #define CMP_LEN 30      // Size of string to hold a compound
// #define ELEM_LEN 10     // Size of string to hold a component

// int main(){

//     char compound[CMP_LEN]; // String representing a compound
//     char elem[ELEM_LEN];    // One elemental component
//     int first, next;

//     /*  Gets data string representing a compound    */
//     printf("Enter a compound> ");
//     scanf("%s", compound);

//     /*  Displays each elemental component, these are identified by an initial capital letter    */

//     first = 0;  // initialise variable to zero
//     for (next = 1; next < (strlen(compound)); ++next) {
//         if (compound[next] >= 'A' && compound[next] <= 'Z'){
//             strncpy(elem, &compound[first], next - first);
//             elem[next - first] = '\0';
//             printf("%s\n", elem);
//             first = next;
//         }
        
//     }

//     /*  Displays the last component */

//     printf("%s\n", strcpy(elem, &compound[first]));

//     return 0;
// }