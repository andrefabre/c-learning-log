/*
*   A function that calls itself is said to be recursive
*   Recursive Function: function that calls itself or that is part of a cycle in the sequence of function calls
*   The ability to invoke itself enables a recursive function to be repeated with different parameter values
*
*   The recursive algorithm that we write will generally consist of an if statement with the following form:
*   if 'this is a simple case'
*       'solve it'
*   else
*       'redefine the problem using recursion' 
*
*/

/*
*   FIGURE 9.4 Counting Occurrences of a Character in a String
*/

#include <stdio.h>

int main(){

    char str[80];   // string to be processed
    char target;    // character counted
    int my_count;

    printf("Enter up to 79 characters.\n");
    gets(str);  // read in the string

    printf("Enter the character you want to count: ");
    scanf("%c", &target);

    my_count = count(target, str);
    printf("The number of occurrences of %c in\n\"%s\"\nis %d\n", target, str, my_count);

    return 0;

}

/*
*   Counts the number of times ch occurs in string str.
*   Pre: Letter ch and string str are defined.
*/

int count(char ch, const char *str){

    int ans;

    if (str[0] == '\0')     // simple case
        ans = 0;
    else                    // redefine problem using recursion
        if (ch == str[0])
            ans = 1 + count(ch, &str[1]); // first character must be counted
        else    // first character is not counted
            ans = count(ch, &str[1]);
    
    return (ans);
}

/*
*   Detailed explanation of how the code above works
*
*   char ch: the target character to count
*   const char *str: a string pointer(a char* of array of characters)
*
*   1. Base case - stopping condition
*   if (str[0] == '\0')     // simple case
*        ans = 0;
*   If the first character of the string is the null terminator ('\0'), the string is empty -> return 0
*   This prevents infinite recursion and ends the process.
*
*   2. Recursive case (do the work)
*   else                    
*       if (ch == str[0])
*           ans = 1 + count(ch, &str[1]); // first character must be counted
*       else    // first character is not counted
*           ans = count(ch, &str[1]);
*   If the first character matches the target:
*       Count 1
*       Recur on the rest of the string (str[1])
*   If if doesnt match:
*       Don't count this character
*       Just recurse on the rest of the string 
*/