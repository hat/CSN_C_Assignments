/* Tony Hendrick, CIT 131, pa02-1 */
/* Converts milliseconds to hours, minutes, and seconds */

#include <stdio.h>

int main( void )
{
    /* Declares the variables */
    long millis; /* Input - the amount of milliseconds */
    long seconds; /* Output - the amount of seconds */
    long minutes; /* Output- the amount of minutes */
    long hours; /* Output - the amount of hours */
    
    /* Gets the amount of milliseconds */
    printf("Enter milliseconds: ");
    scanf("%d", &millis);
    
    /* Converts milliseconds to seconds, minutes, and hours */
    seconds = ((millis / 1000) % 60);
    
    minutes = (((millis / 1000) / 60) % 60);
    
    hours = ((millis / 1000) / 3600);
    
    /* Prints the time in hours, minutes, and seconds */
    printf("%ld : %ld : %ld",hours, minutes, seconds);
}
