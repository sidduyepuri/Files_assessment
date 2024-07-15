/*Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab 
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write 
a function for the other direction as well, converting escape sequences into the real characters.	*/
/*
 * Author: Yepuri Siddu
 * Created: 16 April, 2024
 * Modified: 16 April, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS */
#define LINELEN 1000

/* MAIN FUNCTION */
int main() 
{
    int c, i = 0, j = 0;  // Declaration and initialization of integer variables
    char lines[LINELEN];  // Declaration of character array to store input

    // Read characters from standard input until EOF or until LINELEN - 1 characters are read
    for (; i < LINELEN - 1 && (c = getchar()) != EOF; i++) {
        if (c == '\n') {  // If newline character is encountered
            lines[j++] = '\\';  // Replace newline with '\n'
            lines[j++] = 'n';
        } else if (c == '\t') {  // If tab character is encountered
            lines[j++] = '\\';  // Replace tab with '\t'
            lines[j++] = 't';
        } else {  // For all other characters
            lines[j++] = c;  // Copy the character as it is
        }
    }

    lines[j] = '\0';  // Null-terminate the character array to make it a string

    printf("\n%s\n", lines);  // Print the modified input

    return 0;
}

