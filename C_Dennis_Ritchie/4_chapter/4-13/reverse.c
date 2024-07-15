/* Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place.
 * Author: Yepuri Siddu
 * Created: 19 April, 2024
 * Modified: 19 April, 2024
 * */
/* REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS */
#define MAXLEN 100  /

// Function prototype
void reverse(char str[]);

/* MAIN FUNCTION */
int main(void)
{
	// Sample string
	char str[MAXLEN] = "This is just a string";

	// Print original string
	printf("%s\n", str);

	// Reverse the string
	reverse(str);

	// Print reversed string
	printf("%s\n", str);

	return 0;
}

// Function to reverse a string recursively
void reverse(char str[])
{

	static int j = 0;  // Static variable to maintain position for the reversed string

	// Check if the current character is not the null terminator
	if (str[i] != '\0')
	{
		char c = str[i++];  // Get the current character
		reverse(str);  // Recursive call to reverse the rest of the string

		str[j++] = c;  // Add the character to the reversed string
	}

	// Check if the entire string has been reversed
	if (str[j] == '\0')
	{
		i = 0;  // Reset position for the original string
		j = 0;  // Reset position for the reversed string
	}
}

