/* 
 * Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
 * Author: Yepuri Siddu
 * Created: 8-April-2024
 * Modified: 8-April-2024
 * */

/*REQUIRED HEADER FILES	*/
#include <stdio.h>

// Define the tab increment size
#define TABINC 8

int main(void)
{
    int nb, pos, c; // nb: number of blanks to be added, pos: current position, c: current character
    nb = 0;         // Initialize the number of blanks to 0
    pos = 1;        // Initialize the position to 1

    // Read characters from input until End Of File (EOF)
    while((c = getchar()) != EOF)
    {
        if (c == '\t') // If the character is a tab
        {
            // Calculate the number of spaces needed to reach the next tab stop
            nb = TABINC - ((pos - 1) % TABINC);
            // Output the calculated number of spaces
            while(nb > 0)
            {
                putchar('*');
                ++pos; // Increment the position for each space
                --nb;  // Decrement the number of spaces needed
            }
        }
        else if (c == '\n') // If the character is a newline
        {
            putchar(c); // Output the newline character
            pos = 1;    // Reset the position to 1
        }
        else // For any other character
        {
            putchar(c); // Output the character as it is
            ++pos;      // Increment the position
        }
    }
    return 0; // Return 0 to indicate successful execution
}

