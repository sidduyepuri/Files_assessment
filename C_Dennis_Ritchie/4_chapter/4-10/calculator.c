/*Exercise 4-10. An alternate organization uses getline to read an entire input line; this makes getch and ungetch unnecessary. Revise the calculator to use this approach. 
 * Author: Yepuri Siddu
 * Created: 19 April, 2024
 * Modified: 19 April, 2024
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
#define MAXLEN 1000
#define NUMBER '0'

#define VARSET '_'
#define VARGET 'a'
#define VARNUM 26

/* ENUM DECLARATIONS */
enum boolean {
	FALSE,
	TRUE
};

// Function prototypes
int get_line(char line[], unsigned int max_line_len);
int getop(char[]);
void push(double f);
double pop(void);
int is_empty(void);
void view_head(void);
void duplicate(void);
void swap(void);
void clear(void);

// Global variables
char var = '0';            // Current variable being operated on
char line[MAXLEN];         // Input line buffer
int line_i = 0;            // Current position in input line buffer

/* MAIN FUNCTIONS */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	int varindex = 0;
	double var_buff[VARNUM];

	// Main loop for reading and processing input lines
	while (get_line(line, MAXLEN) != 0)
	{
		line_i = 0; // Reset position in input line buffer
		while ((type = getop(s)) != '\0')
		{
			switch (type)
			{
				case NUMBER:
					push(atof(s)); // Operand, push onto stack
					break;

				case '+':
					push(pop() + pop()); // Addition
					break;

				case '-':
					op2 = pop();
					push(pop() - op2); // Subtraction
					break;

				case '*':
					push(pop() * pop()); // Multiplication
					break;

				case '/':
					op2 = pop();
					if (op2 != 0.0)
					{
						push(pop() / op2); // Division
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
						push((int)pop() % (int)op2); // Modulus
					}
					else
					{
						printf("Error: zero divisor.\n");
					}
					break;

				case '^':
					op2 = pop();
					push(pow(pop(), op2)); // Exponentiation
					break;

				case '~':
					push(sin(pop())); // Sine
					break;

				case 'e':
					push(exp(pop())); // Exponential
					break;

				case 'h':
					view_head(); // View top of stack
					break;

				case 'd':
					duplicate(); // Duplicate top of stack
					break;

				case 's':
					swap(); // Swap top two elements of stack
					break;

				case 'c':
					clear(); // Clear stack
					break;

				case VARSET:
					var_buff[varindex++] = pop(); // Store variable value
					printf("variable %c: %.3f\n", 'a' + varindex - 1, var_buff[varindex - 1]);
					break;

				case VARGET:
					push(var_buff[var - 'a']); // Retrieve variable value
					break;

				case '\n':
					if (!is_empty())
					{
						printf("result: %.8g\n", pop()); // Print result
					}
					break;

				default:
					printf("Error: unknown command %s.\n", s); // Unknown command
					break;
			}
		}
	}

	return 0;
}

// Stack implementation
int sp = 0;
double stack[MAXVAL];

/* PUSH into the stack */
void push(double f)
{
	if (sp < MAXVAL)
	{
		stack[sp++] = f; // Push onto stack
	}
	else
	{
		printf("Error: stack full.\n");
	}
}

/* POP from the stack */
double pop(void)
{
	if (sp > 0)
	{
		return stack[--sp]; // Pop from stack
	}
	else
	{
		printf("Error: stack empty.\n");
	}

	return 0.0;
}

/* Checking if stack is empty */
int is_empty(void)
{
	if (sp > 0)
	{
		return FALSE; // Stack is not empty
	}

	return TRUE; // Stack is empty
}

/*View top element of the stack */
void view_head(void)
{
	if (sp)
	{
		printf("stack_head: %g\n", stack[sp - 1]); // View top of stack
	}
	else
	{
		printf("Error: stack empty.\n");
	}
}

/* Duplicate the top of the stack */
void duplicate(void)
{
	double temp = pop();
	push(temp);
	push(temp); // Duplicate top of stack
}

/* swap top two elements of the stack */
void swap(void)
{
	double temp1 = pop();
	double temp2 = pop();

	push(temp1);
	push(temp2); // Swap top two elements of stack
}

/* Clear the stack */
void clear(void)
{
	do
	{
		stack[sp] = 0.0; // Clear stack
	} while (sp--);
}

// Function to read a line from input
int get_line(char line[], unsigned int max_line_len)
{
	int c, i;

	for (i = 0; i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;
	}

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

// Function to get next operator or operand
int getop(char s[])
{
	int i = 0, c;

	while ((s[0] = c = line[line_i++]) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (isalpha(c))
	{
		var = c;
		return VARGET; // Variable
	}

	if (!isdigit(c) && c != '.' && c != '-')
	{
		return c; // Operator or character
	}

	if (c == '-')
	{
		int next = line[line_i++];
		if (next == '\n' || next == ' ' || next == '\t' || next == '\0')
		{
			--line_i;
			return '-'; // Return '-' as operator
		}
		else if (!isdigit(next) && next != '.') // not a number
		{
			return next; // Not a number
		}
		else
		{
			s[++i] = c = next;
		}
	}
	else
	{
		c = line[line_i++];
	}

	if (isdigit(c))
	{
		while (isdigit(s[++i] = c = line[line_i++]))
			;
	}

	if (c == '.')
	{
		while (isdigit(s[++i] = c = line[line_i++]))
			;
	}

	--line_i;

	return NUMBER;
}
