/*Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none. */
/*
 * Author: Yepuri Siddu
 * Created: 17 April, 2024
 * Modified: 17 April, 2024
 * */

/* *REQUIRED HEADER FILES */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function prototype for strindex
int strindex(char str1[], char str2[]);

/* *MAIN FUNCITON 
 *
 * */

int main()
{
    // Declaring character arrays to store input strings
    char str1[100], str2[100];
    
    // Getting input strings from user
    scanf("%[^\n]s", str1); // Taking input until newline character
    scanf("%s", str2);       // Taking input as a single word
    
    // Calling strindex function to find the position of str2 in str1
    int result = strindex(str1, str2);
    
    // Checking if the result is found or not
    if (result == 0)
        printf("not found\n");
    else
        printf("String %s found in %s at position %d\n", str2, str1, result + 1);
    
    return 0;
}

// Function to find the starting position of str2 in str1
int strindex(char str1[], char str2[])
{
    // Initializing variables
    int i = 0, j = 0, tmp, flag = 0;
    
    // Getting the length of str2
    int len = strlen(str2);
    
    // Looping through str1 until the end
    for (; str1[i] != '\0';)
    {
        // Checking if characters match, case insensitive
        if (tolower(str1[i]) == tolower(str2[j]))
        {
            // Looping through both strings as long as characters match
            while (tolower(str1[i]) == tolower(str2[j]) && str1[i] != '\0')
                i++, j++;
            
            // If str2 is fully matched in str1, set flag and store the position
            if (str2[j] == '\0')
            {
                flag = 1;
                tmp = i;
            }
            j = 0; // Resetting j for next iteration
        }
        else
            i++; // Move to the next character in str1
    }
    
    // If flag is set, return the starting position of str2 in str1
    if (flag == 1)
        return tmp - len;
    
    // If not found, return 0
    return 0;
}

