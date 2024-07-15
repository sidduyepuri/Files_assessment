/*Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.	*/
/*
 * Author: Yepuri Siddu
 * Created: 16 April, 2024
 * Modified: 16 April, 2024
 * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* *MACRO DEFINITIONS */
#define LEN 100

// Function prototypes
void itoa(char str[], long int lx);
void str_rev(char str[]);

/* *MAIN PROGRAM 
 *
 * */

int main()
{
    long int lx; // Declare a long integer variable
    char str[LEN]; // Declare a character array to store the converted string

    // Prompt the user to enter a long integer
    scanf("%ld", &lx);

    // Check if the input long integer is within the range of int data type
    if (lx >= INT_MIN && lx <= INT_MAX)
        itoa(str, lx); // Convert the long integer to a string if it's within the range
    else
    {
        printf("not in range\n"); // Print an error message if the long integer is not within the range of int data type
        return 0; // Exit the program
    }

    str_rev(str); // Reverse the converted string
    printf("%s\n", str); // Print the reversed string
    return 0; // Return 0 to indicate successful execution
}

// Function to convert a long integer to a string
void itoa(char str[], long int lx)
{
    int i = 0, isign = 1; // Declare variables for iteration and sign

    // Check if the long integer is negative
    if (lx < 0)
    {
        isign = -1; // Set the sign to negative
        lx = -lx; // Make the long integer positive
    }

    // Convert the long integer to a string
    while (lx)
    {
        str[i++] = lx % 10 + 48; // Convert each digit to its ASCII representation and store it in the string
        lx = lx / 10; // Update the long integer by removing the last digit
    }

    // Add '-' sign to the string if the long integer was negative
    if (isign == -1)
        str[i++] = '-';

    str[i] = '\0'; // Add null terminator to mark the end of the string
}

// Function to reverse a string
void str_rev(char str[])
{
    int ilen = strlen(str) - 1, i = 0, itmp; // Declare variables for string length and iteration

    // Swap characters from the beginning and end of the string until the middle is reached
    for (; i < ilen; i++, ilen--)
    {
        itmp = str[i]; // Store the current character in a temporary variable
        str[i] = str[ilen]; // Assign the character at the end to the current position
        str[ilen] = itmp; // Assign the character from the temporary variable to the end position
    }
    return; // Return from the function
}

