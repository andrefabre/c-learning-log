/*
*   Pointers can be used to store a memory cell address and access or modify the contents
*   of the cell through indirect reference
*
*   Pointer or pointer variable: a memory cell that stores the address of a data item
*
*   The declaration
*   float *p;
*   identifies as a pointer variable of type "pointer to float". This means that we can store
*   the 'memory address' of a type 'float' variable in p. 
*
*   Indirect reference: accessing the contents of a memory cell through a pointer variable 
*   that stores it address
*
*   Pointers to Files
*   C allows a program to explicitly name a file from which the program will take input or write output
*   To use files in this way, we must declare pointer variables of type FILE *. The statements
*   
*   FILE *inp;  // pointer to input file
*   FILE *outp; // pointer to output file
*
*   declare that the file pointer variables inp and outp will hold information allowing access
*   to the programs input and output files respectively
*/

/*
*   FIGURE 6.2 Program Using File Pointers
*
*   Inputs each number from an input and writes it
*   rounded to 2 decimal places on a line of an output file. 
*/

#include <stdio.h>

int main(){

    FILE *inp;  // pointer to input file
    FILE *outp; // pointer to output file
    double item;
    int input_status;    // status value returned by fscanf

    // Prepare files for input or output

    inp = fopen("indata.txt", "r");
    outp = fopen("outdata.tx", "w");

    // Input each item, format it, and write it

    input_status = fscanf(inp, "%lf", &item);

    while (input_status == 1) {
        fprintf(outp, "%.2f", &item);
        input_status = fscanf(inp, "%lf", &item);
    }

    // Close the files

    fclose(inp);
    fclose(outp);

    return 0;

}