#include <stdio.h>
/*Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else. */
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
/* * MAIN FUNCTION */
int main()
{
    int x, count = 0;

    // Input an integer
    scanf("%d", &x);

    // Loop until x becomes 0
    while (x) {
        // Turn off the rightmost set bit in x and update x
        x = x & (x - 1);

        // Increment the count of set bits
        count++;
    }

    // Print the count of set bits
    printf("No of set bits: %d\n", count);

    return 0;
}

