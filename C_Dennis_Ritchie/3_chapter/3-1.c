
/*Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside.) Write a version with only one test inside the loop and measure the difference in run-time. */
/*
 * Author: Yepuri Siddu
 * Created: 16 April, 2024
 * Modified: 16 April, 2024
 * */
/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>

/* MACRO DEFINITIONS */
#define ARRSIZE 100

/* MAIN FUNCTION */
int main() {
    char str[ARRSIZE];  // Input string
    int i = 0, j = 0, k, flag = 0;  // Variables for looping, searching, and flag for indicating search result
    int arr[ARRSIZE] = {};  // Array to store extracted numbers

    // Prompt user to input array elements
    printf("Enter array elements: ");
    // Input the string until newline character and store it in str
    scanf("%[^\n]s", str);

    // Prompt user to input the element to search for
    printf("Enter element for search: ");
    scanf("%d", &k);  // Input the element to search for and store it in k

    // Loop through each character in the input string
    for (; str[i] != '\0';) {
        // Check if the current character is neither a space nor a digit
        if (!isspace(str[i]) && !isdigit(str[i])) {
            printf("Enter digits only\n");  // Print error message and exit if non-digit character found
            return 0;
        }

        // Extract digits and build numbers until a non-digit character is encountered
        while (isdigit(str[i])) {
            arr[j] = arr[j] * 10 + str[i] - '0';  // Convert character to integer and add it to the current number
            i++;  // Move to the next character
        }
        j++;  // Move to the next slot in the array to store the next number

        // Skip whitespace characters
        while (isspace(str[i]))
            i++;

        // Check if the current extracted number matches the search element
        if (arr[j - 1] == k) {
            flag = 1;  // Set flag to indicate element found
            break;  // Exit loop since element is found
        }
    }

    // Print search result
    if (flag == 1)
        printf("Element %d found in array index %d\n", k, j - 1);
    else
        printf("Element %d not found in array\n", k);

    return 0;
}

