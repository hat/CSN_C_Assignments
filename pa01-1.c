/* Tony Hendrick, CIT 131, pa01-1 */
/* Converts a temperature from degrees fahrenheit to degrees celsius */

#include <stdio.h>

 int main( void )
 {
	int fahrenheit; /* input - degrees in fahrenheit */
	double celsius; /* output - degrees in celsius */
	
    /* gets the degrees in fahrneheit */
	printf("Enter the degrees fahrenheit: ");
    scanf("%i", &fahrenheit);
    
    /* converts degrees fahrenheit to degrees celsius */
    celsius = 5.0 / 9.0 * (fahrenheit - 32);
    
    /* prints the degrees fahrenheit in degrees celsius */
    printf("That equals %f degrees celsius. \n", celsius);
    
    return 0;
 }
 
