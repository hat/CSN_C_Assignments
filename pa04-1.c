/*
 * @file pa04-1.c
 * @author Tony Hendrick
 * @version 3-4-2014
 * Calculates the day of the week given the year, month,
 * and day of the month.
 */

#include <stdio.h>

int main( void )
{
    int year; /* Input - The year, must be non-negative */
    int month; /* Input - The month, must be between 1 and 12 */
    int dayOfMonth; /* Input - The day of the month, must be between 1 and 31 */
    int yearOfCentury; /* Input - What century the year is in */
    int century; /* Input - the century */
    int dayOfWeek; /* Output - The day of the week */

    /* Prints what the user will enter and gets the year */
    printf( "Enter the year, month, and day of month. \n" );

    printf( "Year (e.g. 2014):" );
    scanf( "%d", &year );

    /* Checks to see if the year entered is a positive number */
    if( year < 0 ) {
        puts( "Error: the year can not be negative. \n" );
    } else {
        /* Gets the month */
        printf( "Month (e.g. 1-12):" );
        scanf( "%d", &month );

        /* Checks to make sure the month is between 1 and 12 */
        if( month < 1 || month > 12 ) {
            puts( "Error: the month must be between 1 and 12. \n" );
        } else {
            /* Gets the day of the month */
            printf( "Day of Month (e.g. 1-31):" );
            scanf( "%d", &dayOfMonth );

            /*Checks to make sure the day of the month is between 1 and 31 */
            if( dayOfMonth < 1 || dayOfMonth > 31 ) {
                puts( "Error: the day of month must be between 1 and 31. \n" );
            } else {
                if( month == 1 || month == 2 ) {
                    month = month + 12;
                    year = year - 1;
                }

                /* Calculates the year of century and the century */
                yearOfCentury = year % 100;

                century = year / 100;

                /* The formula to calculate the day of week based on the information given */
                dayOfWeek = ( dayOfMonth + 13 * (month + 1) / 5 + yearOfCentury + yearOfCentury / 4 + century / 4 + 5 * century  ) % 7;

                /* A switch case that displays the day of the week based on the dayOfWeek formula */
                switch( dayOfWeek ) {
                case 0:
                    puts( "Saturday" );
                    break;
                case 1:
                    puts( "Sunday" );
                    break;
                case 2:
                    puts( "Monday" );
                    break;
                case 3:
                    puts( "Tuesday" );
                    break;
                case 4:
                    puts( "Wednesday" );
                    break;
                case 5:
                    puts( "Thursday" );
                    break;
                case 6:
                    puts( "Friday" );
                    break;
                }
            }
        }

    }
    return 0;
}
