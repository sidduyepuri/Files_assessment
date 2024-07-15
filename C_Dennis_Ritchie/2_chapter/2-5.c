
/*Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. 
(The standard library function strpbrk does the same job but returns a pointer to the 
location.) 	*/
/*
 * Author: Yepuri Siddu
 * Created: 15-April-2024
 * Modified: 15-April-2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/* * MAIN FUNCTION */
int main()
{
    int i = 0, flag = 0;
    char str1[100], str2[50];

    // Read two strings from the user
    scanf("%s %s", str1, str2);

    // Loop through each character in str1
    for (; str1[i] != '\0'; i++) {
        // Check if the current character of str1 is present in str2
        if (strchr(str2, str1[i]) != NULL) {
            flag = 1; // Set flag if a duplicate character is found
            break;    // Exit the loop if a duplicate character is found
        }
    }

    // Check the flag to determine if any duplicate character was found
    if (flag == 0)
        printf("No duplicate characters found.\n");
    else
        printf("Duplicate character found at position %d in string 1.\n", i);

    return 0;
}

