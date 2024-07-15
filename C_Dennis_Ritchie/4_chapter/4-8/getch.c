/*Exercise 4-8. Suppose that there will never be more than one character of pushback. Modify getch and ungetch accordingly.
 * Author: Yepuri Siddu
 * Created: 18 April, 2024
 * Modified: 18 April, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>

// Function prototypes
int getch(void);
void ungetch(int c);

/* MAIN FUNCTION */
int main(void)
{
	char c; 

	while( (c = getch())!=EOF)
	{       
		// Read a character from input
		ungetch(c);             // Push the character back into the input buffer
		printf("%c\n", c = getch()); // Read a character from input again and print it
	}
	return 0;
}

int buf = -1;  // Buffer to store one character

int getch(void)
{
	char temp;

	if (buf != -1)  // If the buffer is not empty
	{
		temp = buf;   // Retrieve character from buffer
		buf = -1;     // Reset buffer

		return temp;  // Return the character
	}

	return getchar();  // Otherwise, get character from standard input
}

void ungetch(int c)
{
	if (buf != -1)  // If the buffer is full
	{
		printf("ungetch: buffer full\n"); // Print error message
	}
	else
	{
		buf = c;  // Otherwise, store character in buffer
	}
}

