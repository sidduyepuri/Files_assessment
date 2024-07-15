/* *Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a 
hexadecimal integer in s. 	*/
/* *
 * Author: Yepuri Siddu
 * Created: 16 April, 2024
 * Modified: 16 April, 2024
 * */

/* *REQUIRED HEADER FILES*/
#include <stdio.h>
#include <string.h>

/* *MACRO DEFINITIONS */
#define SIZE 100

/* *FUNCTION PROTOTYPES	*/
void itob(int,char *,int);
void str_rev(char str[]);

/* *MAIN PROGRAM 
 *
 * */

int main()
{
    int in, ibase; // Declare variables for the input number and its base
    char str[SIZE]; // Declare a character array to store the converted number as a string

    // Prompt the user to enter the number and its base
    printf("Enter number and its base:");
    scanf("%d%d", &in, &ibase);

    // Check if the base is valid
    if (ibase <= 0)
    {
        printf("Enter a valid base value\n");
        return 0; // Exit the program if the base is invalid
    }

    itob(in, str, ibase); // Convert the input number to the specified base and store it in the character array
    str_rev(str); // Reverse the converted string

    printf("%s\n", str); // Print the converted number
    return 0; // Return 0 to indicate successful execution
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

// Function to convert an integer to a string in a given base
void itob(int in, char str[], int ibase)
{
    int i, itmp; // Declare variables for iteration and temporary storage

    // Convert the integer to the specified base
    for (i = 0; in > 0; i++)
    {
        itmp = in % ibase; // Calculate the remainder when dividing by the base

        // Convert the remainder to the corresponding character representation
        if (itmp < 10)
            itmp = itmp + 48; // If the remainder is less than 10, add ASCII offset for digits
        else
            itmp = itmp + 55; // If the remainder is greater than or equal to 10, add ASCII offset for uppercase letters

        str[i] = itmp; // Store the converted character in the string array
        in = in / ibase; // Update the integer by dividing it by the base
    }

    // Add 'x' and '0' prefix for hexadecimal base
    if (ibase == 16)
    {
        str[i++] = 'x'; // Add 'x' character
        str[i++] = '0'; // Add '0' character
    }

    str[i] = '\0'; // Add null terminator to mark the end of the string
}
