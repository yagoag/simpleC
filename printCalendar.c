/*  Prints the formatted calendar for a month
    based in the number of days and code of
    the starting day of the week of the month.

    Author: Yago Arroyo
    Date:   Oct 25th, 2013
*/

#include <stdio.h>

// Function prototype
void printCalendar(int, int);

int main() {
    int numDays, dayOfWeek;

    printf("Type in the number of days in the month: ");
    scanf("%d", &numDays);
    printf("Type in the starting day of the week of the month: ");
    scanf("%d", &dayOfWeek);

    printCalendar(numDays, dayOfWeek);

    return 0;
}

/*  Function:  printCalendar
    Objective: Print a formatted calendar of a month based
               on the number os days and starting day of
               the week of it.
    Parametres:
     - numDays (value): Number of days of the month
     - dayOfWeek (value): Code for the day of the week
                          (0 = Sunday, 1 = Monday etc.)
    Return: None
*/
void printCalendar(int numDays, int dayOfWeek) {
    // Local variables for counters
    int i, j;

    // Prints the header of the calendar
    printf("\nSun Mon Tue Wed Thu Fri Sat\n");

    // Skips the days of the week prior to day one's
    for (i = 0; i < dayOfWeek; i++)
        printf("    ");
    j = dayOfWeek;

    // Prints the days in the calendar
    // i: current day of the month
    // j: current day of the week
    for (i = 1; i <= numDays; i++) {
        printf(" %2d ", i); // Prints the day
        j++;               // Increments the current day of the week
        if (j > 6) {
            printf("\n");  // Starts another line
            j = 0;         // Starts the count of the day of the week again
        }
    }
}
