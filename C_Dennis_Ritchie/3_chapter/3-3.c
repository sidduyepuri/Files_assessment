#include <stdio.h>
#include <stdio.h>
/*Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in 
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either 
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange 
that a leading or trailing - is taken literally.*/
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */

// Function prototype for expand
void expand(char str1[], char str2[]);

int main() {
    char str1[100], str2[100]; // Declaration of input and output strings
    
    // Input a string until newline character and store it in str1
    scanf("%[^\n]s", str1);
    
    // Call expand function to expand shorthand notations and store the result in str2
    expand(str1, str2);
    
    // Print the expanded string
    printf("%s\n", str2);
    
    return 0;
}

// Function to expand shorthand notations like a-z into the equivalent complete list abc...xyz
void expand(char str1[], char str2[]) {
    int i = 0, j = 0; // Index variables for str1 and str2
    int ch; // Temporary variable to hold characters during expansion
    
    // Loop through each character in str1
    for (; str1[i] != '\0'; i++) {
        if (str1[i] == '-') { // If the current character is '-'
            j--; // Decrement j to overwrite the '-' from previous character
            
            // Expand shorthand notation
            for (ch = str1[i - 1]; ch < str1[i + 1]; ch++)
                str2[j++] = ch; // Store each expanded character in str2
        } else {
            str2[j++] = str1[i]; // Copy the character from str1 to str2
        }
    }
    str2[j] = '\0'; // Null-terminate str2 to make it a valid string
}

