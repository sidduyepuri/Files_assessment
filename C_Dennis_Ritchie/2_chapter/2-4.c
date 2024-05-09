/*Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in 
s1 that matches any character in the string s2. */
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 100

// Function prototype for removing duplicate characters
void remove_duplicates(char str1[], char str2[]);

// Function prototype for converting string to lowercase
void str_lwr(char str[]);

int main() 
{
	char str1[MAXSIZE], str2[MAXSIZE];

	// Read two strings with spaces until newline character is encountered
	scanf("%[^\n]s", str1);
	scanf(" %[^\n]s", str2);

	// Remove duplicates from str1 based on characters present in str2
	remove_duplicates(str1, str2);

	// Print the modified string str1 after removing duplicates
	printf("%s\n", str1);

	return 0;
}

// Function to remove duplicates from str1 based on characters present in str2
void remove_duplicates(char str1[], char str2[]) 
{
	int i = 0, j = 0;

	// Convert str2 to lowercase
	str_lwr(str2);

	// Loop through each character in str1
	for (; str1[i] != '\0'; i++) {
		// Check if the current character in str1 is present in str2
		// If present, skip this character and move to the next one
		while (strchr(str2, tolower(str1[i])) != NULL)
			i++;

		// Copy the character to the new index in str1
		str1[j++] = str1[i];
	}

	// Add null terminator to mark the end of the string
	str1[j] = '\0';
}

// Function to convert string to lowercase
void str_lwr(char str[]) 
{
	int i = 0;

	// Loop through each character in the string
	for (; str[i] != '\0'; i++) {
		// Convert uppercase characters to lowercase
		if (isupper(str[i]))
			str[i] += 32;
	}
}

