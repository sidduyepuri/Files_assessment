#include <stdio.h>

/* Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. */
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
int main(void) 
{
    char Ic;

    // Loop until EOF is encountered
    while ((Ic = getchar()) != EOF) {
        // If current character is a tab, replace it with \t
        if (Ic == '\t') {
            putchar('\\'); // Print '\'
            putchar('t');  // Print t
        }
        // If current character is a backspace, replace it with \b
        else if (Ic == '\b') {
            putchar('\\'); // Print '\'
            putchar('b');  // Print b
        }
        // If current character is a backslash, replace it with 
        else if (Ic == '\\') {
            putchar('\\'); // Print '\'
            putchar('\\'); // Print '\'
        }
        // Otherwise, print the character as it is
        else
            putchar(Ic);
    }

    return 0;
}

