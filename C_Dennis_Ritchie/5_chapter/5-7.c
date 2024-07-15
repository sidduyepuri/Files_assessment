/*
 * 
 * Exercise 5-7. Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain stora
 * How much faster is the program?
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*MACRO DEFINITIONS */
#define MAXLINES 5000 
#define MAXLEN 1000 
#define MAXSTORE 10000 

/*FUNCTION PROTOTYPES */
char *line_ptr[MAXLINES];

// Function prototypes
size_t get_line(char line[], size_t max_line_len);
int readlines(char *line_ptr[], int max_nr_of_lines, char *stored_lines);
void writelines(char *line_ptr[], int nr_of_lines);
void swap(char *v[], int i, int j);
void quick_sort(char *line_ptr[], int left, int right);

int main() {
    int nr_of_lines; // Number of input lines read
    char stored_lines[MAXSTORE]; // Characters to be stored for all lines

    // Read lines from input and check if the number of lines is within limit
    if ((nr_of_lines = readlines(line_ptr, MAXLINES, stored_lines)) >= 0) {
        // Sort the lines
        quick_sort(line_ptr, 0, nr_of_lines - 1);
        printf("-----\n");
        // Write the sorted lines
        writelines(line_ptr, nr_of_lines);
        return 0;
    } else {
        // Error if input is too big to sort
        printf("Error: input too big to sort.\n");
        return 1;
    }
}

/* readlines: read input lines, store them in stored_lines buffer,
   and store pointers to them in line_ptr array */
int readlines(char *line_ptr[], int max_nr_of_lines, char *stored_lines) {
    int len;
    int nr_of_lines = 0; // Number of lines read
    char *p = stored_lines; // Pointer to the current position in stored_lines
    char line[MAXLEN]; // Buffer for the current input line

    // Read lines until end-of-file or error
    while ((len = get_line(line, MAXLEN)) > 0) {
        // Check if we have exceeded the maximum number of lines or storage space
        if (nr_of_lines >= max_nr_of_lines || (stored_lines + MAXSTORE - p) < len) {
            return -1;
        } else {
            line[len - 1] = '\0'; // Replace newline with null terminator
            strcpy(p, line); // Copy line to stored_lines buffer
            line_ptr[nr_of_lines++] = p; // Store pointer to the line
            p += len; // Move p to the next position
        }
    }
    return nr_of_lines; // Return the number of lines read
}

/* writelines: write output lines */
void writelines(char *line_ptr[], int nr_of_lines) {
    while (nr_of_lines-- > 0) {
        printf("%s\n", *line_ptr++);
    }
}

/* get_line: read a line into line array, return length */
size_t get_line(char line[], size_t max_line_len) {
    int c;
    size_t i;

    for (i = 0; i < max_line_len - 1 && (c = getc(stdin)) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0'; // Null-terminate the line
    return i;
}

/* quick_sort: sort v[left]...v[right] into increasing order */
void quick_sort(char *v[], int left, int right) {
    int i, last;

    if (left >= right) { // Do nothing if the array contains less than two elements
        return;
    }

    swap(v, left, (left + right) / 2); // Move the partition element to v[0]
    last = left;

    for (i = left + 1; i <= right; ++i) {
        if (strcmp(v[i], v[left]) < 0) {
            swap(v, ++last, i); // Move smaller elements to the left
        }
    }

    swap(v, left, last); // Restore partition element
    quick_sort(v, left, last - 1); // Recursively sort left part
    quick_sort(v, last + 1, right); // Recursively sort right part
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

