//Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
/*
 * Author: Yepuri Siddu
 * Created: 12-April-2024
 * Modified: 12-April-2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS	*/
#define LIMIT 1000

/* MAIN FUNCTIONS	*/
int main() 
{
    int i, c;
    char s[LIMIT];
    int condition_met = 0; // Flag to indicate whether loop termination condition has been met

    // Loop through input characters, storing them in 's' array
    for (i = 0; i < LIMIT - 1; ++i) {
        c = getchar(); // Read a character from input

        // Check if the character is a newline or EOF
        if (c == '\n' || c == EOF) {
            condition_met = 1; // Set flag to indicate termination condition met
            break; // Exit loop if newline or EOF is encountered
        }

        // Store the character in 's' array
        s[i] = c;
    }

    // Ensure proper termination of the string with a null character
    s[i] = '\0';

    // Check if the loop termination condition was met
    if (condition_met == 1) {
        printf("%s\n", s); // If condition met, print the string stored in 's'
    }

    return 0;
}

