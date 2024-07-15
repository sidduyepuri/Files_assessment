/*Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.
 * Author: Yepuri Siddu
 * Created: 19 April, 2024
 * Modified: 19 April, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>

/* Function Prototypes */
void printd(int n,char str[]);

/* Global Variables */
int num=0;

/* MAIN FUNCTION */
int main() {
    int n;
    char str[100];  // Character array to store the string representation of the integer

    // Read an integer from the user
    scanf("%d", &n);

    // Convert the integer to a string and store it in 'str'
    printd(n, str);

    // Print the resulting string
    printf("%s\n", str);

    return 0;
}

// Recursive function to convert an integer to a string
void printd(int n, char str[]) {
    static int i = 0;  // Static variable to keep track of the position in the string

    // If the number is negative, add a '-' to the string and make the number positive
    if (n < 0) {
        str[i++] = '-';
        n = -n;
    }

    // If the number has more digits, recursively call the function
    if (n / 10) {
        printd(n / 10, str);
    } else {
        str[i] = '\0';  // Place the null-terminator at the end of the string
    }

    // Add the least significant digit to the string
    str[i++] = n % 10 + '0';
}

