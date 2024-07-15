/*
 * Author: Yepuri Siddu
 * Created: 21 April, 2024
 * Modified: 21 April, 2024
 * */
/* REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS */
#define MAX_SIZE 100 

// Function prototype
void get_line(char *s);

/* MAIN FUNCTION */
int main(void) {
    char string[MAX_SIZE]; // Declare a char array to hold the input string

    // Call get_line to read a line of input into the string
    get_line(string);

    // Output the string using puts
    puts(string);

    return 0;
}

/* get_line: read a line of input into s, up to a newline or EOF */
void get_line(char *s) {
    // Read characters one by one until newline or EOF is encountered
    while ((*s = getchar()) != EOF && (*s != '\n')) {
        ++s; // Move to the next position in the array
    }

    *s = '\0'; // Null-terminate the string
}

