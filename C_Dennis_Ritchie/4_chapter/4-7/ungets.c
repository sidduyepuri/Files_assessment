/*
 * Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input.Should ungets know about buf and bufp, or should it just use ungetch?
 * Author: Yepuri Siddu
 * Created: 18 April, 2024
 * Modified: 18 April, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/* MACRO DEFINITIONS */
#define MAXLEN 1000   
#define BUFFSIZE 1000

// Function prototypes
int getstr(char line[], int limit);
void ungetstr(char line[]);

/* MAIN FUNCTION */
int main(void)
{
	char line[MAXLEN];  // Input string
	char temp[MAXLEN];  // Temporary string for demonstration
			    // Read a string from input and print it
	getstr(line, MAXLEN);
	printf("%s", line);

	// Push the previously read string back into the input buffer
	ungetstr(line);

	// Read another string from input and print it
	getstr(temp, MAXLEN);
	printf("%s", temp);

	return 0;
}

// Function to read a string from input
int getch(void);
void ungetch(int c);

int getstr(char line[], int limit)
{
	int i = 0, c;

	// Read characters until EOF, newline, or limit is reached
	while (limit - 1 > 0 && (c = getch()) != EOF && c != '\n')
	{
		line[i++] = c;
	}

	// If newline encountered, include it in the string
	if (c == '\n')
	{
		line[i++] = c;
	}

	// Terminate the string
	line[i] = '\0';

	return i; // Return the length of the string
}

// Function to push a string back into the input buffer
void ungetstr(char line[])
{
	int i = strlen(line);

	// Push each character of the string back into the input buffer
	while (i)
	{
		ungetch(line[--i]);
	}
}

// Buffer and functions for character input
int bufp = 0;
char buf[BUFFSIZE];

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar(); // Get a character from the buffer or input
}

void ungetch(int c)
{
	if (bufp >= BUFFSIZE)
	{
		printf("ungetch: too many characters\n"); // Print error if buffer is full
	}
	else
	{
		buf[bufp++] = c; // Push character back into the buffer
	}
}

