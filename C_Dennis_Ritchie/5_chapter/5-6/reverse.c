/*
 * Author: Yepuri Siddu
 * Created: 21 April, 2024
 * Modified: 21 April, 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/*MACRO DEFINITIONS */
#define SIZE 100 

/* Function prototype */
void reverse(char *s);

/* MAIN FUNCTION */
int main(void) {
    char s[SIZE]; 

    // Read a line of input from the user
    scanf("%[^\n]s", s);

    // Call reverse to reverse the string
    reverse(s);

    // Output the reversed string using puts
    puts(s);

    return 0;
}

/* reverse: reverse the string s in place */
void reverse(char *s) {
    int len = strlen(s) - 1; // Get the length of the string (excluding the null terminator)
    char tmp; // Temporary variable for swapping

    // Loop to swap characters from the start and end moving towards the center
    for (int i = 0; i < len; i++, len--) {
        tmp = *(s + i);      // Store the current character from the start
        *(s + i) = *(s + len); // Replace it with the current character from the end
        *(s + len) = tmp;      // Place the stored character at the end
    }
}

