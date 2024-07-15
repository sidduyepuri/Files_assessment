/*
 * Author: Yepuri Siddu
 * Created: 21 April, 2024
 * Modified: 21 April, 2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>
#include <string.h>

/*MACRO DEFINITIONS */
#define SIZE 100

// Function prototypes
void reverse(char *s);
void itoa(char *s, int n);

/* MAIN FUNCTION */
int main(void) 
{
	int i;
	char s[SIZE];

	scanf("%d",&i);
	// Convert integer to string using itoa
	itoa(s, i);

	// Print the converted string
	printf("String: %s\n", s);

	return 0;
}

/* reverse: reverse the string s in place */
void reverse(char *s) 
{
	char *t = s + strlen(s) - 1; // Pointer to the end of the string
	char aux;

	// If the string is empty, return immediately
	if (*s == '\0')
		return;

	// Swap characters from the start and end moving towards the center
	while (s < t) {
		aux = *t;
		*t-- = *s;
		*s++ = aux;
	}
}

/* itoa: convert integer n to string s */
void itoa(char *s, int n) 
{
	char *t = s; // Pointer to iterate over the string 
	int sign=1;
	if(n<0){
		sign=-1;
		n=-n;
	}
	// Handle the case where n is 0
	if (n == 0) {
		*t++ = '0';
		*t = '\0';
		return;
	}

	// Convert each digit to a character and store it in the string
	while (n) {
		*(t++) = n % 10 + '0';
		n /= 10;
	}
	if(sign==-1)
	{
		*t++='-';
	}
	*t = '\0'; // Null-terminate the string
	// Reverse the string to get the correct order
    	reverse(s);
}

