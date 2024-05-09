#include <stdio.h>

/* Exercise 1-7. Write a program to print the value of EOF. */
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
int main()
{
    int Ic;

    // Read characters from input until EOF is encountered
    Ic = getchar();
    while (Ic != EOF) {
        // Print the character read
        putchar(Ic);

        // Read the next character
        Ic = getchar();
    }

    // Print the value of EOF after the loop ends
    printf(" %c %d\n", Ic, EOF);

    return 0;
}

