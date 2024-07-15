/* Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after 
the last non-blank character that occurs before the n-th column of input. Make sure your 
program does something intelligent with very long lines, and if there are no blanks or tabs 
before the specified column.
 * Author: Yepuri Siddu
 * Created: 8-April-2024
 * Modified: 8-April-2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>

/* MACRO DEFINITIONS */
#define MAXLINE 10000 
#define TRUE (1 == 1) 
#define FALSE !TRUE
#define BREAKING_POINT 10 
#define OFFSET 10

/* Function Prototypes	*/
int get_line(char line[], int max_line_len);
void fold_line(char line[], char fold_str[], int n_break);

int main(void)
{
    char line[MAXLINE];      // Array to hold the input line
    char fold_str[MAXLINE];  // Array to hold the folded line

    // Read lines from input until EOF
    while ((get_line(line, MAXLINE)) > 0)
    {
        // Fold the line at the defined breaking point and store it in fold_str
        fold_line(line, fold_str, BREAKING_POINT);
        // Print the folded line
        printf("%s", fold_str);
    }

    return 0; // Return 0 to indicate successful execution
}

// Function to read a line from input
int get_line(char line[], int max_line_len)
{
    int c, i = 0;

    // Read characters until max line length, EOF, or newline is encountered
    while (i < max_line_len - 1 && (c = getchar()) != EOF && c != '\n')
    {
        line[i++] = c;
    }

    // If newline is encountered, add it to the line
    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0'; // Null-terminate the line

    return i; // Return the length of the line
}

// Function to fold a line at the given breaking point
void fold_line(char line[], char fold_str[], int n_break)
{
    int i, j;               // Indices for input line and folded line
    int column = 0;         // Current column position in the line
    int split = FALSE;      // Flag to indicate if the line should be split
    int last_blank = 0;     // Position of the last blank character

    // Loop through each character in the input line
    for (i = 0, j = 0; line[i] != '\0'; ++i, ++j)
    {
        fold_str[j] = line[i]; // Copy character to the folded line

        if (fold_str[j] == '\n') // Reset column if newline is encountered
        {
            column = 0;
        }

        column++; // Increment the column position

        if (column == n_break - OFFSET) // Check if near the breaking point
        {
            split = TRUE; // Set the split flag
        }

        // Track the position of the last blank character for potential split
        if (split && (fold_str[j] == ' ' || fold_str[j] == '\t'))
        {
            last_blank = j;
        }

        // If the breaking point is reached
        if (column == n_break)
        {
            if (last_blank) // If there was a blank character to split at
            {
                fold_str[last_blank] = '\n'; // Replace blank with newline
                column = j - last_blank;     // Adjust the column position
                last_blank = 0;              // Reset last blank position
            }
            else // If no blank character to split at
            {
                fold_str[j++] = line[i]; // Copy current character
                fold_str[j++] = '-';     // Add a hyphen
                fold_str[j] = '\n';      // Add a newline

                column = 0; // Reset the column position
            }

            split = FALSE; // Reset the split flag
        }
    }

    fold_str[j] = '\0'; // Null-terminate the folded line
}

