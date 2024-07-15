/*Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do  it in full generality.) 
 * Author: Yepuri Siddu
 * Created: 10-April-2024
 * Modified: 10-April-2024
 * */

/* REQUIRED HEADER FILES	*/
#include <stdio.h>

/*MACRO DEFINITIONS	*/
#define MAXSTR 10000 
#define TRUE (1 == 1) 
#define FALSE !TRUE  

/* Function Prototypes	*/
int get_str(char str[], int limit);
void check_syntax(char str[]);

/* MAIN FUNCTION	*/
int main(void)
{
	char str[MAXSTR]; // Array to hold the input string

	get_str(str, MAXSTR); // Read the input string
	check_syntax(str);    // Check the syntax of the input string

	return 0; // Return 0 to indicate successful execution
}

// Function to read a string from input
int get_str(char str[], int limit)
{
	int c, i = 0;

	// Read characters until the limit is reached or EOF is encountered
	while (i < limit - 1 && (c = getchar()) != EOF)
	{
		str[i++] = c;
	}
	str[i] = '\0'; // Null-terminate the string

	return i; // Return the length of the string
}

// Function to check the syntax of the input string
void check_syntax(char str[])
{
	int parentheses = 0;     // Counter for parentheses
	int brackets = 0;        // Counter for brackets
	int braces = 0;          // Counter for braces

	int single_quotes = FALSE;  // Flag for single quotes
	int double_quotes = FALSE;  // Flag for double quotes

	int block_comment = FALSE;  // Flag for block comments
	int line_comment = FALSE;   // Flag for line comments

	int i = 0;
	while (str[i] != '\0' && parentheses >= 0 && brackets >= 0 && braces >= 0)
	{
		// Check characters outside of comments and quotes
		if (!line_comment && !block_comment && !single_quotes && !double_quotes)
		{
			if (str[i] == '(')
			{
				++parentheses; // Increment parentheses counter
			}
			else if (str[i] == ')')
			{
				--parentheses; // Decrement parentheses counter
			}

			if (str[i] == '[')
			{
				++brackets; // Increment brackets counter
			}
			else if (str[i] == ']')
			{
				--brackets; // Decrement brackets counter
			}

			if (str[i] == '{')
			{
				++braces; // Increment braces counter
			}
			else if (str[i] == '}')
			{
				--braces; // Decrement braces counter
			}
		}

		// Check for single and double quotes outside of comments
		if (!line_comment && !block_comment)
		{
			if (str[i] == '\'' && !single_quotes && !double_quotes)
			{
				single_quotes = TRUE; // Enter single quotes
			}
			else if (single_quotes && str[i] == '\'' && (str[i - 1] != '\\' || str[i - 2] == '\\'))
			{
				single_quotes = FALSE; // Exit single quotes
			}

			if (str[i] == '"' && !single_quotes && !double_quotes)
			{
				double_quotes = TRUE; // Enter double quotes
			}
			else if (double_quotes && str[i] == '"' && (str[i - 1] != '\\' || str[i - 2] == '\\'))
			{
				double_quotes = FALSE; // Exit double quotes
			}
		}

		// Check for comments outside of quotes
		if (!single_quotes && !double_quotes)
		{
			if (str[i] == '/' && str[i + 1] == '*' && !line_comment)
			{
				block_comment = TRUE; // Enter block comment
			}
			else if (str[i] == '*' && str[i + 1] == '/')
			{
				block_comment = FALSE; // Exit block comment
			}

			if (str[i] == '/' && str[i + 1] == '/' && !block_comment)
			{
				line_comment = TRUE; // Enter line comment
			}
			else if (str[i] == '\n')
			{
				line_comment = FALSE; // Exit line comment
			}
		}

		++i; // Move to the next character
	}

	// Check for unbalanced symbols and unclosed quotes/comments
	if (parentheses)
	{
		printf("Error: unbalanced parentheses.\n");
	}

	if (brackets)
	{
		printf("Error: unbalanced brackets.\n");
	}

	if (braces)
	{
		printf("Error: unbalanced braces.\n");
	}

	if (single_quotes)
	{
		printf("Error: unbalanced single quotes.\n");
	}

	if (double_quotes)
	{
		printf("Error: unbalanced double quotes.\n");
	}

	if (block_comment)
	{
		printf("Error: block comment not closed.\n");
	}
}

