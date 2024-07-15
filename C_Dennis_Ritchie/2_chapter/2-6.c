/*Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged. */
/*
 * Author: Yepuri Siddu
 * Created: 15-April-2024
 * Modified: 15-April-2024
 * */

//* Required Header
#include <stdio.h>

//Function prototypes
void printbinary(int num, int size);

/* main function */
int main() 
{
    int x, y, p, n, temp;

    // Input values for x, y, p, and n
    scanf("%d %d", &x, &y);
    printf("Enter p and n:");
    scanf("%d %d", &p, &n);

    // Check for negative values of x and y
    if (x < 0 || y < 0) {
        printf("Enter positive values for x and y.\n");
        return 0;
    }

    // Check if n is greater than p+1
    if (n > p + 1) {
        printf("Insufficient bits.\n");
        return 0;
    }

    // Print binary representations of x and y
    printbinary(x, sizeof(x));
    printbinary(y, sizeof(y));

    // Create mask to extract rightmost n bits of y
    temp = (1 << n) - 1;

    // Shift and mask y to get the bits to be set in x
    y = (y & temp) << (p - n + 1);

    // Clear the bits in x at positions p to p-n+1 and set them with y
    x = (x & ~(temp << (p - n + 1))) | y;

    // Print binary representation of modified x
    printbinary(x, sizeof(x));

    printf("x = %d\n", x);

    return 0;
}

// Function to print binary representation of a number
void printbinary(int num, int size) {
    int i;
    for (i = size * 8 - 1; i >= 0; i--) {
        if (num & (1 << i))
            printf("1");
        else
            printf("0");
        if ((i + 1) % 8 == 0)
            printf(" ");
    }
    printf("\n");
}

