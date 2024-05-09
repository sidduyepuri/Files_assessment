#include <stdio.h>
#include <limits.h>
/*Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers 
and by direct computation. Harder if you compute them: determine the ranges of the various 
floating-point types. 	*/
/*
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
/* * MAIN FUNTION */
int main() 
{
    printf("==============> integer ranges <================\n");
    printf("signed int min: %d\n", INT_MIN);
    printf("signed int max: %d\n", INT_MAX);
    printf("unsigned int max: %u\n", UINT_MAX); // Use %u for unsigned int
    printf("long int min: %ld\n", LONG_MIN);
    printf("long int max: %ld\n", LONG_MAX);
    printf("unsigned long int max: %lu\n", ULONG_MAX); // Use %lu for unsigned long int
    printf("==============> short int ranges <================\n");
    printf("signed short int min: %d\n", SHRT_MIN);
    printf("signed short int max: %d\n", SHRT_MAX);
    printf("unsigned short int max: %u\n", USHRT_MAX); // Use %u for unsigned short int
    printf("==============> character ranges <================\n");
    printf("unsigned char max: %u\n", UCHAR_MAX); // Use %u for unsigned char
    printf("signed char min: %d\n", SCHAR_MIN);
    printf("signed char max: %d\n", SCHAR_MAX);
    printf("==============> long ranges <================\n");
    printf("unsigned long max: %lu\n", ULONG_MAX); // Use %lu for unsigned long
    printf("signed long min: %ld\n", LONG_MIN);
    printf("signed long max: %ld\n", LONG_MAX);
    return 0;
}

