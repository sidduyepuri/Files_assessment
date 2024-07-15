/*Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise
 * Author: Yepuri Siddu
 * Created: 21 April, 2024
 * Modified: 21 April, 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/*MACRO DEFINITIONS */
#define MAX_SIZE 100

/* Function prototypes */
int strend(char *str1, char *str2);

/*
 * main():Main function reads main string and substring , checking that substring found by calling strend()
 * if not found return 0
 * if found return 1
 * */
int main() {
	char str1[MAX_SIZE];
	char str2[MAX_SIZE];

	// Prompt user to enter the main string
	printf("Enter main string: ");
	scanf("%[^\n]s", str1);

	// Clear the input buffer and prompt user to enter the substring
	printf("Enter sub string: ");
	scanf(" %s", str2);

	// Call strend to check if str2 is at the end of str1
	int res = strend(str1, str2);

	// Print the result based on the return value of strend
	if (res == 1) {
		printf("Substring found at end\n");
	} else {
		printf("Not found\n");
	}

	return 0;
}

/* 
 * strend: return 1 if str2 occurs at the end of str1, otherwise return 0 
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
int strend(char *str1, char *str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	// If str2 is longer than str1, it can't be at the end of str1
	if (len2 > len1) {
		return 0;
	}

	// Move the pointer str1 to the position where comparison should start
	str1 += (len1 - len2);

	// Compare str1 and str2
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return 0; // Characters do not match
		}
		str1++;
		str2++;
	}

	// If we reach the end of str2, it means str2 is at the end of str1
	return (*str2 == '\0') ? 1 : 0;
}


