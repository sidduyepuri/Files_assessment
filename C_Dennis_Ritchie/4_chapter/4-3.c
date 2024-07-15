/*Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add 
the modulus (%) operator and provisions for negative numbers.
 * Author: Yepuri Siddu
 * Created: 17 April, 2024
 * Modified: 26 April, 2024
 * */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100   /* max size of operand or operator */
#define BUFSIZE 100 /* buffer size for ungetch */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100  /* maximum depth of val stack */

int getop(char []);
int sp = 0;               /* next free stack position */
double val[MAXVAL];       /* value stack */

void push(double);
double pop(void);
int getch(void);
void ungetch(int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

/* reverse Polish calculator */
int main()
{
    int type, temp;
    double op2, op1;
    char s[MAXOP];

    // Loop to get input and perform operations
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));  // If the token is a number, push it onto the stack
                break;
            case '+':
                push(pop() + pop());  // Addition operation
                break;
            case '*':
                push(pop() * pop());  // Multiplication operation
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);    // Subtraction operation
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);  // Division operation
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                op1 = pop();
                if (op2 > 0.0 && op1 >= 0.0)
                    push((int)op1 % (int)op2);  // Modulo operation with positive operands
                else if (op2 != 0.0 && op1 < 0.0) {
                    temp = (int)op1 % (int)op2;  // Modulo operation with negative dividend
                    if (temp < 0)
                        push(temp + op2);        // Adjusting result to be positive
                }
                else if (op2 < 0.0 && op1 > 0.0) {
                    temp = (int)op1 % (int)op2;  // Modulo operation with negative divisor
                    if (temp > op2)
                        push(temp + op2);        // Adjusting result to be positive
                }
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());  // Print the result
                break;
            default:
                printf("error: unknown command %s\n", s);  // Error for unknown command
                break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;   // Pushing the value onto the stack
    else
        printf("error: stack full, can't push %g\n", f);  // Error if stack is full
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];  // Popping the top value from the stack
    else {
        printf("error: stack empty\n");  // Error if stack is empty
        return 0.0;
    }
}

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c, k;

    // Skipping white spaces
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (c == '-') {
        k = getchar();
        if (isdigit(k)) {
            s[1] = k;
            return NUMBER;  // Negative number
        }
        return c;  // Minus operator
    }

    if (!isdigit(c) && c != '.')
        return c;  // Not a number

    i = 0;

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);  // Pushing back the character not used for number parsing

    return NUMBER;
}

/* get a (possibly pushed-back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();  // Returning the next character
}

/* push character back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");  // Error if buffer is full
    else
        buf[bufp++] = c;  // Pushing the character back to the buffer
}

