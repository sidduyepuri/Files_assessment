/*
 * Author: Yepuri Siddu
 * Created: 21 April, 2024
 * Modified: 21 April, 2024
 * */

/*REQUIRED HEADER FILES*/
#include <stdio.h>

/*MACRO DEFINITIONS */
#define SIZE 100

/* Function prototype */
int strindex(char *s, char *t);

/* MAIN FUNCTION */
int main(void) {
    int ret;
    char str1[SIZE]; // Declare a char array to hold the main string
    char str2[SIZE]; // Declare a char array to hold the substring

    // Prompt the user to enter the main string
    printf("Enter Main string: ");
    scanf("%[^\n]", str1);

    // Clear input buffer
    while (getchar() != '\n');

    // Prompt the user to enter the substring
    printf("Enter Sub string: ");
    scanf("%[^\n]", str2);

    // Call strindex to find the substring in the main string
    ret = strindex(str1, str2);

    // Print the result based on the return value of strindex
    if (ret == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", ret);

    return 0;
}

/* strindex: return the index of the first occurrence of t in s, -1 if not found */
int strindex(char *str1, char *str2) 
{
    char *first;  // Pointer to iterate over the main string
    char *second; // Pointer to iterate over the substring
    int pos = 0;  // Variable to track the current position in the main string

    // Loop through each character in the main string
    while (*str1 != '\0') {
        // Check if the current character matches the first character of the substring
        if (*str1 == *str2) {
            first = str1;    // Save the current position in the main string
            second = str2;   // Start comparing with the substring from the beginning

            // Loop to compare the remaining characters
            while (*first++ == *second++) {
                // If end of substring is reached, return the current position
                if (*second == '\0')
                    return pos;
            }
        }
        pos++; // Increment the position counter
        str1++;   // Move to the next character in the main string
    }

    return -1; // Return -1 if the substring is not found
}

