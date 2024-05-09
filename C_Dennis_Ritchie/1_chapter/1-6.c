#include <stdio.h>
#include <unistd.h> // Include the header file for the sleep function

int main() {
    int c;

    // Loop until EOF (End of File) is encountered
    while (getchar() != EOF) {
        // Print "1" indicating that a character was received
        printf("1\n");

        // Pause execution for 1 second
        sleep(1);
    }

    // Print "0" indicating that EOF was encountered
    printf("0\n");

    return 0;
}

