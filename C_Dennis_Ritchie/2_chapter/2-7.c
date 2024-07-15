
/*Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at 
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.	*/
/*
 * Author: Yepuri Siddu
 * Created: 15 April, 2024
 * Modified: 15 April, 2024
 * */
/* REQUIRED HEADER FILES */
#include <stdio.h>

/*FUNCTION PROTOTYPES */
void printbinary(int num, int size);

/* MAIN FUNCTION */
int main() 
{
    int x, p, n, temp;
    
    // Input value for x
    scanf("%d", &x);
    printf("Enter p and n:");
    scanf("%d %d", &p, &n);
    
    // Check for negative value of x
    if (x < 0) {
        printf("Enter positive value for x.\n");
        return 0;
    }
    
    // Check if n is greater than p+1
    if (n > p + 1) {
        printf("Insufficient bits.\n");
        return 0;
    }
    
    // Print binary representation of x
    printbinary(x, sizeof(x));
    
    // Create mask to toggle the bits
    temp = (1 << n) - 1;
    
    // Toggle the n bits starting from position p
    x ^= (temp << (p - n + 1));
    
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

