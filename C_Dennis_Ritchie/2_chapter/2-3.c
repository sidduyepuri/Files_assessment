//Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
/*
 * Author: Yepuri Siddu
 * Created: 12-April-2024
 * Modified: 12-April-2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

/* MACRO DEFINITIONS */
#define MAXSIZE 100

/* MAIN FUNCTIONS */
int main() 
{
    int i, num = 0, temp, result = 0, flag = 0;
    char str[MAXSIZE];

    // Read input hexadecimal string
    scanf("%s", str);

    // Calculate length of the input string
    int len = strlen(str);

    // Loop through each character in the input string
    for (i = 0; str[i] != '\0'; i++) {
        // If the current character is '0' and the next character is 'x' or 'X',
        // skip these characters as they represent the prefix for hexadecimal numbers
        if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
            i += 2;

        // Convert the current character to lowercase
        temp = tolower(str[i]);

        // If the character is a digit, convert it to its integer value
        if (isdigit(temp))
            temp -= 48;

        // If the character is an alphabet (a-f), convert it to its integer value
        if (isalpha(temp) && temp <= 'f')
            temp = temp - 'a' + 10;

        // If the character is a valid hexadecimal digit, update the result
        if (isdigit(str[i]) || (tolower(str[i]) >= 'a' && tolower(str[i]) <= 'f'))
            result += temp * (int)pow(16, len - i - 1);
        else {
            // If the character is not a valid hexadecimal digit, print an error message and exit
            printf("Enter valid hexadecimal number.\n");
            return 0;
        }
    }

    // Print the decimal equivalent of the hexadecimal number
    printf("%d\n", result);

    return 0;
}

