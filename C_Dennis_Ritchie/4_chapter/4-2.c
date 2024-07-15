/*Exercise 4-2. Extend atof to handle scientific notation of the form 
 * 123.45e-6
 * where a floating-point number may be followed by e or E and an optionally signed exponent.
 * Author: Yepuri Siddu
 * Created: 17,April 2024
 * Modified: 25,April 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>

/*MACRO DEFINITIONS */
#define MAXLEN 500 // Maximum length of the input line

// Function prototypes
int get_line(char line[], unsigned int max_line_len);
double atof(char s[]);

/*
 * MAIN(): main function read one line from stdin by calling get_line function and convert that string to float equalant value 
 * */

int main(void)
{
	char line[MAXLEN];

	// Get a line of input from the user
	get_line(line, MAXLEN);
	// Print the input line
	printf("%s\n", line);
	// Convert the input line to a floating-point number and print it
	printf("%f\n", atof(line));

	return 0;
}

/**
 * get_line(): This function reads one line from stdin and return i value.
 * Author: Yepuri Siddu
 * Created: 17,April 2024
 * Modified: 25,April 2024
 * */
int get_line(char line[], unsigned int max_line_len)
{
	int i = 0;
	int c;

	// Read characters until end of line or maximum length is reached
	while (i < max_line_len - 1 && (c = getchar()) != '\n' && c != EOF)
	{
		line[i++] = c;
	}

	// Null-terminate the string
	line[i] = '\0';

	return i;
}

/**
 * atof(): This function takes string as an argument and that string into a floating value
 * Author: Yepuri Siddu
 * Created: 10,may 2024
 * Modified: 25,may 2024
 * */
double atof(char s[])
{
	double val = 0.0;
	double power = 1.0;
	int i = 0;
	int sign = 1;
	int exp_sign = 1;
	int exp_pwr = 0;

	// Skip white space
	while (isspace(s[i]))
		++i;

	// Check for sign
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;

	// Process integer part
	while (isdigit(s[i]))
		val = 10.0 * val + (s[i++] - '0');

	// Process fractional part
	if (s[i] == '.')
		++i;
	while (isdigit(s[i]))
	{
		val = 10.0 * val + (s[i++] - '0');
		power *= 10.0;
	}

	// Process exponent part
	if (s[i] == 'e' || s[i] == 'E')
	{
		++i;
		if (s[i] == '-')
		{
			exp_sign = -1;
			++i;
		}
		else if (s[i] == '+')
		{
			++i;
		}

		while (isdigit(s[i]))
			exp_pwr = 10 * exp_pwr + (s[i++] - '0');

		while (exp_pwr > 0)
		{
			if (exp_sign == -1)
				power *= 10.0;
			else
				power /= 10.0;
			--exp_pwr;
		}
	}

	return sign * val / power;
}

