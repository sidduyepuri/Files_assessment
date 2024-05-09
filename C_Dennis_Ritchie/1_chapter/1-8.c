#include <stdio.h>

/* Exercise 1-8. Write a program to count blanks, tabs, and newlines. */
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */

/* * MAIN FUNCTION
 * Main function counts the no of tabs, blanks , lines
 * */

int main() 
{
    int Ic, Ibl = 0, Itab = 0, Inl = 0;

    // Loop until EOF is encountered, counting blanks, tabs, and newlines
    while ((Ic = getchar()) != EOF) {
        if (Ic == '\t')
            Itab++;
        else if (Ic == ' ')
            Ibl++;
        else if (Ic == '\n')
            Inl++;
    }

    // Print the counts of blanks, tabs, and newlines
    printf("blanks=%d tabs=%d lines=%d\n", Ibl, Itab, Inl);

    return 0;
}

