#include <stdio.h>
#include <ctype.h>

int main(){

    char c;
    c = getchar();

    printf("Get a character %c and assign it to the variable c\n", c);

    printf("putchar should print the character enter to the screen again\n\n");
    putchar(c);

    return 0;
}