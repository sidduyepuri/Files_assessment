/* Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
 * Author: Yepuri Siddu
 * Created: 19 April, 2024
 * Modified: 19 April, 2024
 * */
/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* MACRO DEFINITIONS */
#define MAXOP 100   
#define MAXVAL 100 
#define BUFFSIZE 100  
#define NUMBER '0'  

// Function prototypes
int getop(char[]);
void push(double);
double pop(void);

/* MAIN FUNCTION */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];  // Buffer for storing operator or operand

	// Main loop for reading and processing input
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));  // Push operand onto stack
				break;

			case '+':
				push(pop() + pop());  // Addition
				break;

			case '-':
				op2 = pop();
				push(pop() - op2);  // Subtraction
				break;

			case '*':
				push(pop() * pop());  // Multiplication
				break;

			case '/':
				op2 = pop();
				if (op2 != 0.0)
				{
					push(pop() / op2);  // Division
				}
				else
				{
					printf("Error: zero divisor.\n");
				}
				break;

			case '%':
				op2 = pop();
				if (op2 != 0.0)
				{
					push((int)pop() % (int)op2);  // Modulus
				}
				else
				{
					printf("Error: zero divisor.\n");
				}
				break;

			case '\n':
				printf("result: %.8g\n", pop());  // Print result
				break;

			default:
				printf("Error: unknown command %s.\n", s);  // Unknown command
				break;
		}
	}

	return 0;
}

int sp = 0;          // Stack pointer
double val[MAXVAL];  // Stack storage

// Function to push a value onto the stack
void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;  // Push onto stack
	}
	else
	{
		printf("Error: stack full, can't push %g.\n", f);  // Stack overflow
	}
}

// Function to pop a value from the stack
double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];  // Pop from stack
	}
	else
	{
		printf("Error: stack empty.\n");  // Stack underflow
		return 0.0;
	}
}

// Function to get the next operator or operand
int getop(char s[])
{
	int i = 0, c;
	static int buf = EOF;  // Static variable to store character for next call

	// Skip whitespace
	while ((s[0] = c = getchar()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;  // Not a number
	}

	if (c == '-')
	{
		int next = getchar();
		if (!isdigit(next) && next != '.')
		{
			return next;  // Not a number
		}

		s[i] = c;
		c = next = buf;  // Use buffered character
	}
	else
	{
		c = getchar();
	}

	// Collect integer part
	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getchar()))
			;
	}

	// Collect fraction part
	if (c == '.')
	{
		while (isdigit(s[++i] = c = getchar()))
			;
	}

	if (c != EOF)
	{
		buf = c;  // Save next character
	}

	return NUMBER;  // Signal that a number was found
}

