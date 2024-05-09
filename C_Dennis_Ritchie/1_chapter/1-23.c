#include <stdio.h>
/*Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to 
handle quoted strings and character constants properly. C comments don't nest. */
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
#define MAXSTR 10000

#define TRUE (1 == 1)   /* Define TRUE */
#define FALSE !TRUE     /* Define FALSE */

// This is a test comment.

int get_str(char str[], int limit); // This is another test comment.
void remove_comments(char str[], char no_com_str[]);

int main(void) 
{
	/**
	 * This is multiline
	 * block
	 * comment.
	 */

	char str[MAXSTR];   /* Original string */
	char no_com_str[MAXSTR];    /* String without comments */

	get_str(str, MAXSTR);   /* Get input string */

	remove_comments(str, no_com_str);   /* Remove comments */

	printf("%s", no_com_str);   /* Output string without comments */

	return 0;
}

/* Function to get input string */
int get_str(char str[], int limit) {
	int c, i = 0;

	/* Read characters until EOF or limit is reached */
	while (i < limit - 1 && (c = getchar()) != EOF) {
		str[i++] = c;
	}
	str[i] = '\0';  /* Null-terminate string */

	return i;
}

/* Function to remove comments from a string */
void remove_comments(char str[], char no_com_str[]) {
	int in_quote = FALSE;   /* Flag to track if inside quotes */
	int line_comment = FALSE;   /* Flag to track line comments */
	int block_comment = FALSE;  /* Flag to track block comments */

	int i = 0, j = 0;
	/* Loop through each character in the string */
	while (str[i] != '\0') {
		if (!block_comment) {
			if (!in_quote && str[i] == '"') {
				in_quote = TRUE;    /* Entering quote */
			} else if (in_quote && str[i] == '"') {
				in_quote = FALSE;   /* Exiting quote */
			}
		}

		/* Check for comments */
		if (!in_quote) {
			if (str[i] == '/' && str[i + 1] == '*' && !line_comment) {
				block_comment = TRUE;   /* Start of block comment */
			}

			if (str[i] == '*' && str[i + 1] == '/') {
				block_comment = FALSE;  /* End of block comment */
				i += 2; /* Skip over comment ending */
			}

			if (str[i] == '/' && str[i + 1] == '/') {
				line_comment = TRUE;    /* Start of line comment */
			}

			if (str[i] == '\n') {
				line_comment = FALSE;   /* End of line comment */
			}

			if (line_comment || block_comment) {
				++i;    /* Skip over comments */
			} else if (!line_comment || !block_comment) {
				no_com_str[j++] = str[i++];    /* Copy non-comment characters */
			}
		} else {
			no_com_str[j++] = str[i++];    /* Copy characters inside quotes */
		}
	}

	no_com_str[j] = '\0';   /* Null-terminate the string */
}

