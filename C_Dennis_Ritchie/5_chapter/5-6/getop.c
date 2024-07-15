/*
 * Author: Yepuri Siddu
 * Created: 21 April, 2024
 * Modified: 21 April, 2024
 * */
/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>

/* MACRO DEFINITIONS */
#define NUMBER 0
#define SIZE 100

/* FUNCTION PROTOTYPES */
int getop(char *s);

/* MAIN FUNCTIONS */
int main(void)
{
	char s[SIZE];
	int type = getop(s);
	puts(s);
	return 0;
}

int getop(char *s)
{
	char c;
	// Skip blanks (spaces and tabs)
	while ((*s = c = getchar()) == ' ' || c == '\t')
		;

	*(s + 1) = '\0';

	// Not a number
	if (!isdigit(c) && c != '.')
		return c;
	// Collect the integer part
	if (isdigit(c) && c != '.')
		while (isdigit(*(++s) = c = getchar()))
			;
	// Collect the fraction part
	if (c == '.')
	{
		while (isdigit(*(++s) = c = getchar()))
			;
	}
	if (c != EOF)
		ungetc(c, stdin);
	*s = '\0';
	return NUMBER;
}
