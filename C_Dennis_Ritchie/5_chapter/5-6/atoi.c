/*
 * Author: Yepuri Siddu
 * Created: 21 April, 2024
 * Modified: 21 April, 2024
 * */

/* REQUIRED HEADER FILES */
#include <stdio.h>

// Function prototype for custom atoi function
int atoi(const char *s);

/* MAIN FUNCTION */
int main(void) {
    int i;
    char s[100];

    // Read a string input from the user
    scanf(" %s", s);

    // Convert the string to an integer using atoi
    i = atoi(s);
    if(i==0)
	    printf("Enter valid input\n");
    else
	    printf("Integer: %d\n", i);

    return 0;
}

/* atoi: convert string s to integer */
int atoi(const char *s) {
    int i = 0,sign=1;
    if(*s=='-'||*s=='+')
    {
	    if(*s=='-')
	    	sign=-1;
	    else
		    sign=1;
	    s++;
    }
    // Loop through each character of the string
    while (*s != '\0' && *s >= '0' && *s <= '9') {
        // Convert the character to integer and add it to the result
        i = i * 10 + (*s - '0');
        ++s; // Move to the next character
    }
    i=i*sign;
    return i; // Return the converted integer
}

