
/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions. */
/*
 * Author: Yepuri Siddu
 * Created: 15 April, 2024
 * Modified: 15 April, 2024
 * */
// REQUIRED HEADER FILES
#include <stdio.h>

// Function prototype
int rightrotate(unsigned int x, int p);
void printbinary(int x, int size);

//MAIN FUNCTION
int main() {
    int x;
    int p;

    // Input values for x and p
    scanf("%d %d", &x, &p);

    // Check if x is non-negative
    if (x < 0) {
        printf("Number must be non-negative.\n");
        return 0;
    }

    // Print binary representation of x before rotation
    printf("Original binary representation:\n");
    printbinary(x, sizeof(x));

    // Right rotate x by p bits
    x = rightrotate(x, p);

    // Print the rotated value of x
    printf("Right rotated value by %d bits: %d\n", p, x);

    // Print binary representation of x after rotation
    printf("Binary representation after rotation:\n");
    printbinary(x, sizeof(x));

    return 0;
}

// Function to perform right rotation on x by p bits
int rightrotate(unsigned int x, int p) {
	int i;
	for (i = 0; i < p; i++) {
		// Check if the rightmost bit is set
		if (x & 0x1) {
			// If set, right shift x by 1 and set the leftmost bit
			x = x >> 1;
			x = x | (0x1 << (sizeof(x) * 8 - 1));
		} else {
			// If not set, right shift x by 1 and clear the leftmost bit
			x = x >> 1;
			x = x & ~(0x1 << (sizeof(x) * 8 - 1));
		}
	}
	return x;
}

// Function to print binary representation of x
void printbinary(int x, int size) {
	int i;
	for (i = 0; i < size * 8; i++) {
		if (x & (0x1 << (size * 8 - 1)))
			printf("1");
		else
			printf("0");
		x = x << 1;
		if ((i + 1) % 8 == 0)
			printf(" ");
	}
	printf("\n");
}
