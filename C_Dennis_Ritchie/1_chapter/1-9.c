#include <stdio.h>

/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
int main(void) 
{
    int Ic;
    int Ilast_c = '\0'; // Initialize last character to null character

    // Loop until EOF is encountered
    while ((Ic = getchar()) != EOF) {
        // If current character is not a space or if last character was not a space, print the character
        if (Ic != ' ' || Ilast_c != ' ')
            putchar(Ic);

        // Update last character to current character
        Ilast_c = Ic;
    }

    return 0;
}

