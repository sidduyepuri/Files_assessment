/* Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */
#include <stdio.h>

// Table to store the number of days in each month for non-leap and leap years
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// Function prototypes
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pda);

int main(int argc, char *argv[])
{
    int d, m, y;

    // Prompt user for day, month, and year
    printf("Enter day, month, and year: ");
    scanf("%d%d%d", &d, &m, &y);

    // Check for invalid input
    if (d == 0 || m == 0)
    {
        printf("Invalid Entry!!\n");
        return 0;
    }

    // Calculate the day of the year
    int day = day_of_year(y, m, d);
    printf("%d-%d is %d day of the year %d\n", d, m, day, y);

    return 0;
}

// Function to calculate the day of the year given the year, month, and day
int day_of_year(int year, int month, int day)
{
    // Determine if the year is a leap year
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    // Check if the month is valid
    if (month > 12)
    {
        printf("Error: a year has 12 months, so please choose a number between 1 and 12.\n");
        return -1;
    }

    // Check if the day is valid for the given month
    if (day > daytab[leap][month])
    {
        printf("Error: the %d month has a maximum of %d days.\n", month, daytab[leap][month]);
        return -2;
    }

    // Calculate the day of the year
    for (int i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}

// Function to determine the month and day given the year and the day of the year
void month_day(int year, int yearday, int *pmonth, int *pda)
{
    // Determine if the year is a leap year
    int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    // Check if the yearday is valid
    if ((!leap && yearday > 365) || (leap && yearday > 366))
    {
        // Reset the provided month and day
        *pmonth = 0;
        *pda = 0;
        printf("Error: year %d has %d days.\n", year, leap ? 366 : 365);
        return;
    }

    // Determine the month and day
    for (int i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pda = yearday;
}

