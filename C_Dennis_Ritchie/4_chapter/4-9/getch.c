/*Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties ought to be if an EOF is pushed back, then implement your design. 
 * Author: Yepuri Siddu
 * Created: 19 April, 2024
 * Modified: 19 April, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS */
#define BUFFSIZE 100 

// Function prototypes
int getch(void);
void ungetch(int c);

/* MAIN FUNCTION */
int main(void)
{
	int c;

	c = getch();     // Read a character from input
	putchar(c);      // Print the character

	ungetch(EOF);    // Push EOF back into the input buffer

	c = getch();     // Read a character from input again
	putchar(c);      // Print the character

	return 0;
}

// Global variables for buffer and buffer pointer
int bufp = 0;     // Buffer pointer
int buf[BUFFSIZE]; // Input buffer

// Function to get a character from input or buffer
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar(); // Get character from buffer or input
}

// Function to push a character back into the buffer
void ungetch(int c)
{
	if (bufp >= BUFFSIZE) // Check if buffer is full
	{
		printf("ungetch: too many characters\n"); // Print error message if buffer is full
	}
	else
	{
		buf[bufp++] = c; // Push character back into buffer
	}
}

