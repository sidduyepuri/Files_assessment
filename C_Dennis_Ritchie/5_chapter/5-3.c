/*Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.
 * Author: Yepuri Siddu
 * Created: 20 April, 2024
 * Modified: 20 April, 2024
 * */
/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/*MACRO DEFINITIONS */
#define MAX_SIZE 100

// Function to concatenate two strings
char* str_cat(char *dest, const char *src);

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];

    // Read the first string from the user
    scanf("%[^\n]", str1);

    // Read the second string from the user
    scanf(" %[^\n]", str2);

    // Check if the first string is just an ampersand
    if (strcmp(str1, "&") == 0) {
        str1[0] = '\0';  // Set the first string to empty
    }

    // Check if the second string is just an ampersand
    if (strcmp(str2, "&") == 0) {
        str2[0] = '\0';  // Set the second string to empty
    }

    // Concatenate the strings using the custom function
    char *res = str_cat(str1, str2);

    // Print the result
    printf("Result: %s\n", res);

    return 0;
}

/* 
 * str_cat():Function to concatenate src string to dest string
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
char* str_cat(char *dest, const char *src) {
    int len = strlen(dest);

    // Copy characters from src to the end of dest
    while ((*(dest+len) = *src++) != '\0') {
        len++;
    }
    return dest; // Return the concatenated string
}
