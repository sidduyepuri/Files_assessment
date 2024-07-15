/*Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.
 * Author: Yepuri Siddu
 * Created: 21 April, 2024
 * Modified: 21 April, 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/*MACRO DEFINITIONS */
#define MAX_SIZE 100

// Function prototypes
void str_ncpy(char *str1, char *str2, int n);
void str_ncat(char *str1, char *str2, int n);
int str_ncmp(char *str1, char *str2, int n);

/*
 * main(): main function takes two strings and one integer value from stdin
 * by calling str_ncpy(),str_ncat(),str_ncmp() functions it can peform those specific tasks
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024 
 * */
int main() 
{
	char str1[MAX_SIZE], str2[MAX_SIZE];
	int choice, n, res = 1;

	// Prompt user to enter the first string
	printf("Enter string 1: ");
	scanf("%[^\n]s", str1);

	// Prompt user to enter the second string
	printf("Enter string 2: ");
	scanf(" %s", str2);

	// Prompt user to enter the value of n
	printf("Enter n value: ");
	scanf("%d", &n);

	// Prompt user to choose an operation
	printf("Choose your option:\n1. strncpy()\n2. strncat()\n3. strncmp()\nEnter your choice: ");
	scanf("%d", &choice);

	// Perform the chosen operation
	switch(choice) {
		case 1: 
			str_ncpy(str1, str2, n);
			break;
		case 2: 
			str_ncat(str1, str2, n);
			break;
		case 3: 
			res = str_ncmp(str1, str2, n);
			break;
		default: 
			printf("Enter valid option.\n");
			return 1;
	}

	// Print the result based on the chosen operation
	if(choice == 1 || choice == 2) {
		printf("%s\n", str1);
	} else if(res == 0 && choice == 3) {
		printf("Same\n");
	} else {
		printf("Not same\n");
	}

	return 0;
}

/* str_ncpy: copy n characters from str2 to str1 */
void str_ncpy(char *str1, char *str2, int n) {
	int i = 0;
	for(; i < n; i++) {
		*str1++ = *str2++;
	}
}

/* str_ncat: concatenate n characters from str2 to the end of str1 */
void str_ncat(char *str1, char *str2, int n) {
	int i = 0;
	// Move str1 to the end of the string
	str1 = str1 + strlen(str1);
	while(i < n) {
		*str1++ = *str2++;
		i++;
	}
	*str1 = '\0'; // Null-terminate the result
}

/* str_ncmp: compare n characters of str1 and str2 */
int str_ncmp(char *str1, char *str2, int n) {
	int i = 0;
	while(i < n) {
		if(*str1 != *str2) {
			return *str1 - *str2; // Return the difference if characters don't match
		}
		i++;
		str1++;
		str2++;
	}
	return 0; // Return 0 if all characters match
}

