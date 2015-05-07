/* Tony Hendrick, CIT 131, pa01-2 */
/* adds all the digits of an integer together */

#include <stdio.h>

 int main( void )
 {
    int given_number; /* input - the number the user wants to use to find the sum of its digits */
    int sum_digits; /* output - the sum of all the digits of the given_number */
    int digits_placeholder; /* process - stores the value of each digit for calculating purposes */
    
    /* gets the integer the user wants to know the sum of the digits of */
    printf("Enter an integer between 1 and 100,000: ");
    scanf("%d", &given_number);
    
    /* calculates the sum of all the digits of the given_number */
    sum_digits = given_number % 10;
    digits_placeholder = given_number / 10;
    sum_digits = sum_digits + (digits_placeholder % 10);
    digits_placeholder = digits_placeholder / 10;
    sum_digits = sum_digits + (digits_placeholder % 10);
    digits_placeholder = digits_placeholder / 10;
    sum_digits = sum_digits + (digits_placeholder % 10);
    digits_placeholder = digits_placeholder / 10;
    sum_digits = sum_digits + (digits_placeholder % 10);
    digits_placeholder = digits_placeholder / 10;
    sum_digits = sum_digits + (digits_placeholder % 10);
    
    /* prints the sum of all the digits of the given_number */
    printf("The sum of all the digits of the entered integer is %d \n", sum_digits);
    
	return 0;
 }
