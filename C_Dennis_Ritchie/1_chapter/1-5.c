//Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0. C
#include <stdio.h>
int main() 
{
    // Declare a variable Ifahr to store temperature in Fahrenheit
    int Ifahr;

    // Loop through temperatures from 300°F to 0°F in steps of 20°F
    for (Ifahr = 300; Ifahr >= 0; Ifahr -= 20) 
    {
        // Calculate corresponding temperature in Celsius using the formula: (5/9)*(Fahrenheit-32)
        float Celsius = (5.0 / 9.0) * (Ifahr - 32);

        // Print the Fahrenheit temperature and its corresponding Celsius temperature
        printf("%3d %6.1f\n", Ifahr, Celsius);
    }

    return 0;
}

