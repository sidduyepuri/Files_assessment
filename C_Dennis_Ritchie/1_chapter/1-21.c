/* 
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum 
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. 
When either a tab or a single blank would suffice to reach a tab stop, which should be given 
preference?
 * Author: Yepuri Siddu
 * Created: 8-April-2024
 * Modified: 8-April-2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>

// Define the tab increment size
#define TABINC 8

int main(void)
{
    int nb, nt, pos, c; // nb: number of blanks, nt: number of tabs, pos: current position, c: current character
    nb = 0;             // Initialize the number of blanks to 0
    nt = 0;             // Initialize the number of tabs to 0

    // Loop through each character in the input until End Of File (EOF)
    for (pos = 1; (c = getchar()) != EOF; ++pos)
    {
        if (c == ' ') // If the character is a space
        {
            // Check if the current position is at a tab stop
            if ((pos % TABINC) != 0)
                ++nb; // Increment the number of blanks if not at a tab stop
            else
            {
                nb = 0; // Reset the number of blanks
                ++nt;   // Increment the number of tabs
            }
        }
        else
        {
            // Output any accumulated tabs
            for (; nt > 0; --nt)
                putchar('\t');
            
            if (c == '\t') // If the character is a tab
                nb = 0;    // Reset the number of blanks
            else
            {
                // Output any accumulated blanks
                for (; nb > 0; --nb)
                    putchar(' ');
            }
            
            putchar(c); // Output the current character
            
            if (c == '\n') // If the character is a newline
                pos = 0;   // Reset the position counter
            else if (c == '\t') // If the character is a tab
                // Adjust the position counter for the next character after the tab
                pos = pos + (TABINC - (pos - 1) % TABINC) - 1;
        }
    }
    return 0; // Return 0 to indicate successful execution
}

