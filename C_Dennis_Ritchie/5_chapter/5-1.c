/*Exercise 5-1. As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.
 * Author: Yepuri Siddu
 * Created: 20 April, 2024
 * Modified: 20 may, 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>

/*MACRO DEFINITIONS */
#define BUFSIZE 100

/* GLOBAL DECLARATIONS */
char buf[BUFSIZE]; 
int bufp = 0;      

// Function prototypes
int getch(void);
void ungetch(int);
int getint(int *pn);

int main(void) {
    int n = 0;
    int sign;

    // Call getint and check the return value
    sign = getint(&n);

    // Check if the input is valid
    if (n == 0) {
        printf("Invalid Entry!!!\n");
    } else {
        printf("%d\n", n);
    }

    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, d, sign;

    // Skip white space
    while (isspace(c = getch()))
        ;

    // Check for non-digit and non-sign characters
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);  // It's not a number
        return 0;
    }

    // Determine the sign
    sign = (c == '-') ? -1 : 1;

    // Handle optional sign characters
    if (c == '+' || c == '-') {
        d = c;  // Store the sign character
        if (!isdigit(c = getch())) {  // Get the next character
            if (c != EOF)
                ungetch(c);  // Push the character back if not EOF
            ungetch(d);      // Push the sign character back
            return d;
        }
    }

    // Convert input characters to integer
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }

    *pn *= sign; // Apply the sign to the integer

    if (c != EOF)
        ungetch(c); // Push back the character if not EOF

    return c;
}

/* getch: get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

