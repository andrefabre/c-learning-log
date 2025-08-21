/*
*   getchar takes no arguements and returns the character as its result
*   Eiher of the following two expressions can be used to store the next available input character in ch.
*   scanf("%c", &ch)        ch = getchar()
*   To get a single character from a file, use the facility getc.
*/

/*  Implementation of scanline Function Using getchar   
*   Gets one line of data fom standard input. Reurns an empty string
*   on end of file. If data line will no fit in allotted space, stores
*   portion that does fit and discards rest of input line
*/

#include <stdio.h>
#include <ctype.h>

char *scanline(char *dest, // ouput - destination string
                int dest_len)   // input - space available in dest
{
    int i, ch;

    // Gets next line one character at a time
    i = 0;
    for (ch = getchar(); ch != '\n' && ch != EOF && i < dest_len - 1; ch = getchar())
        dest[i++] = ch;
    dest[i] = '\0'; // Null-terminate the string

    // Discards any characters that remain on input line
    while (ch != '\n' && ch != EOF)
        ch = getchar();
    
    return (dest);

}

/*
*   Further explanation of what the FOR loop in the code above
*   for (initialisation; condition; increment) {
*       code to repeat}

*   INITIALISATION: ch = getchar();
*   This reads one character from input and stores it in ch.
*   getchar() reads from standard input (keyboard), one character at a time.
*
*   CONDITION: ch != '\n' && ch != EOF && i < dest_len - 1
*   This means:
*       Continue until:
*           The user presses Enter (\n),
*           Or we hit EOF (end of file or Ctrl+Z/Ctrl+D),
*           Or we've reached the limit of how many characters we want to store (dest_len - 1)
*   The -1 allows space for the null terminator (\0) in a string.
*
*   INCREMENT: ch = getchar();
*   After each loop, read the next character
*
*/

/*
*   FIGURE 8.16 String Function for a Greater-Than Operator that ignores Case
*/

#define STRSIZE 80

/*
*   Converts the lowercase letters of its string argument to uppercase leaving other characters unchanged
*/

char *string_to_upper(char *str) // input/output - string whose lowercase letters are the be replaced by uppercase
{
    int i;
    for (i = 0; i < strlen(str); ++i)
        if (islower(str[i]))
            str[i] = toupper(str[i]);
    
    return(str);
}

/*
*   Compares the two strings of up to STRSIZE characters ignoring the case of
*   the letters. Returns the value 1 if str1 should follow str2 in an
*   alphabetised list; otherwise returns 0
*/

int string_greater(const char *str1, const char *str2) // input strings to compare
{

    char s1[STRSIZE], s2[STRSIZE];

    // Copies str1 and str2 so string_to_upper can modify copies

    strcpy(s1, str1);
    strcpy(s2, str2);

    return(strcmp(string_to_upper(s1)), string_to_upper(s2) > 0);
}