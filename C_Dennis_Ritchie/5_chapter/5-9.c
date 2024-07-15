/* Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing.
 * Author: Yepuri Siddu
 * Created: 8-may-2024
 * Modified: 8-may-2024
 * */

/*REQUIRED HEADER FILES */
#include <stdio.h>

// Arrays to store the number of days in each month for regular and leap years
static char year_month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char leap_year_month_days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Array of pointers to the month day arrays
static char *daytab[2] = {year_month_days, leap_year_month_days};

// Function prototypes
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pda);

int main(void)
{
        int d, m, y;
        scanf("%d%d%d", &d, &m, &y);
        if (d <= 0 || m <= 0 || y <= 0)
        {
                printf("Invalid Entry!!!\n");
                return 0;
        }
        int day = day_of_year(y, m, d);
        printf("Day of the year: %d\n", day);
        return 0;
}

// Function to calculate the day of the year
int day_of_year(int year, int month, int day)
{
        // Determine if the year is a leap year
        int leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

        // Additional checks for month.
        if (month > 12)
        {
                printf("Error: a year has 12 months, so please choose a number between 1 and 12.\n");
                return -1;
        }

        // Additional checks for day.
        if (day > daytab[leap][month])
        {
                printf("Error: the %d month has a maximum of %d days.\n", month, daytab[leap][month]);
                return -2;
        }

        // Calculate the day of the year
        int i;
        for (i = 1; i < month; i++)
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

        // Additional check for yearday.
        if ((!leap && yearday > 365) || (leap && yearday > 366))
        {
                // Reset the provided month and day.
                *pmonth = 0;
                *pda = 0;
                printf("Error: year %d has %d days.\n", year, leap ? 366 : 365);
                return;
        }

        // Determine the month and day
        int i;
        for (i = 0; yearday > daytab[leap][i]; i++)
        {
                yearday -= daytab[leap][i];
        }

        *pmonth = i;
        *pda = yearday;
}

