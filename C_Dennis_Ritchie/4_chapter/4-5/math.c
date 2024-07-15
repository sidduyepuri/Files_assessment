/*Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in 
Appendix B, Section 4. 
 * Author: Yepuri Siddu
 * Created: 18 April, 2024
 * Modified: 18 April, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

/* MACRO DEFINITIONS */
#define MAXOP 100     
#define MAXVAL 100   
#define BUFFSIZE 100  
#define NUMBER '0'  

// Function protoitypes
int getop(char []);
void push(double f);
double pop(void);
void view_head(void);
void duplicate(void);
void swap(void);
void clear(void);

/* MAIN FUNCTION */
int main(void)
{
	int itype;
	double dop2;
	char s[MAXOP];

	// Main loop to process input and execute operations
	while ((itype = getop(s)) != EOF)
	{
		switch (itype)
		{
			case NUMBER:
				push(atof(s));  // Push the number onto the stack
				break;

			case '+':
				push(pop() + pop());  // Pop two numbers, add them, and push the result
				break;

			case '-':
				dop2 = pop();
				push(pop() - dop2);  // Pop two numbers, subtract the second from the first, and push the result
				break;

			case '*':
				push(pop() * pop());  // Pop two numbers, multiply them, and push the result
				break;

			case '/':
				dop2 = pop();
				if (dop2 != 0.0)
				{
					push(pop() / dop2);  // Pop two numbers, divide the first by the second, and push the result
				}
				else
				{
					printf("Error: zero divisor.\n");
				}
				break;

			case '%':
				dop2 = pop();
				if (dop2 != 0.0)
				{
					push(fmod(pop(), dop2));  // Pop two numbers, compute the modulus, and push the result
				}
				else
				{
					printf("Error: zero divisor.\n");
				}
				break;

			case '^':
				dop2 = pop();
				push(pow(pop(), dop2));  // Pop two numbers, raise the first to the power of the second, and push the result
				break;

			case '~':
				push(sin(pop()));  // Pop a number, compute its sine, and push the result
				break;

			case 'e':
				push(exp(pop()));  // Pop a number, compute its exponential, and push the result
				break;

			case 'h':
				view_head();  // View the top element of the stack
				break;

			case 'd':
				duplicate();  // Duplicate the top element of the stack
				break;

			case 's':
				swap();  // Swap the top two elements of the stack
				break;

			case 'c':
				clear();  // Clear the stack
				break;

			case '\n':
				printf("result: %.8g\n", pop());  // Print the result from the top of the stack
				break;

			default:
				printf("Error: unknown command %s.\n", s);  // Handle unknown commands
				break;
		}
	}

	return 0;
}

// External variables for stack operations
int Isp = 0;               // Next free stack position
double stack[MAXVAL];     // Value stack

// Push a value onto the stack
void push(double f)
{
	if (Isp < MAXVAL)
	{
		stack[Isp++] = f;
	}
	else
	{
		printf("Error: stack full.\n");
	}
}

// Pop and return the top value from the stack
double pop(void)
{
	if (Isp > 0)
	{
		return stack[--Isp];
	}
	else
	{
		printf("Error: stack empty.\n");
	}
	return 0.0;
}

// View the top value of the stack without popping it
void view_head(void)
{
	if (Isp > 0)
	{
		printf("stack_head: %g\n", stack[Isp - 1]);
	}
	else
	{
		printf("Error: stack empty.\n");
	}
}

// Duplicate the top value of the stack
void duplicate(void)
{
	double temp = pop();
	push(temp);
	push(temp);
}

// Swap the top two values on the stack
void swap(void)
{
	double temp1 = pop();
	double temp2 = pop();
	push(temp1);
	push(temp2);
}

// Clear the stack
void clear(void)
{
	Isp = 0;
}

// Buffer for ungetch
int bufp = 0;
char buf[BUFFSIZE];

// Get a (possibly pushed back) character
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push character back on input
void ungetch(int c)
{
	if (bufp >= BUFFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}

// Get next operator or numeric operand
int getop(char s[])
{
	int i = 0, c;

	// Skip whiteIspace
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c;  // Not a number
	}

	if (c == '-')
	{
		int next = getch();
		if (next == '\n' || next == ' ' || next == '\t')
		{
			ungetch(next);
			return c; // Return '-' as operator
		}
		else if (!isdigit(next) && next != '.')
		{
			return next; // Not a number
		}
		else // Number like "-5", "-.6" etc, next is digit or '.'
		{
			s[++i] = c = next;
		}
	}
	else
	{
		c = getch();
	}

	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}

	if (c == '.')
	{
		while (isdigit(s[++i] = c = getch()))
			;
	}

	if (c != EOF)
	{
		ungetch(c);
	}

	return NUMBER;
}

