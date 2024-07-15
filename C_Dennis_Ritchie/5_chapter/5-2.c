/* Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?
 * Author: Yepuri Siddu
 * Created: 20 April, 2024
 * Modified: 20 April, 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>

/*MACRO DEFINITIONS */
#define BUFSIZE 100 

/*GLOBAL DECLARATIONS */
char buf[BUFSIZE]; 
int bufp = 0;      

// Function prototypes
int getch(void);
void ungetch(int);
int getfloat(float *pn);

/*
 * Main():Main function read floating value by calling getfloat() function and printing in main function.
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
int main(void) {
    float n;

    // Call getfloat to read a floating-point number from input
    getfloat(&n);

    // Print the floating-point number
    printf("%f\n", n);

    return 0;
}

/* getfloat: get next float from input into *pn 
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
int getfloat(float *pn) {
    int c, sign;
    float power;

    // Skip white space
    while (isspace(c = getch()))
        ;

    // Check for valid input characters
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);  // It's not a number
        return 0;
    }

    // Determine the sign
    sign = (c == '-') ? -1 : 1;

    // Handle optional sign characters
    if (c == '+' || c == '-')
        c = getch();

    // Convert integer part
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    // Handle decimal point
    if (c == '.')
        c = getch();

    // Convert fractional part
    for (power = 1.0; isdigit(c); c = getch(), power *= 10.0)
        *pn = 10.0 * *pn + (c - '0');

    // Apply the sign and scale by the power of 10
    *pn *= sign / power;

    // Push back the character if it's not EOF
    if (c != EOF)
        ungetch(c);

    return c;
}

/* 
 * getch: get a (possibly pushed-back) character 
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* 
 * ungetch: push character back on input 
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

