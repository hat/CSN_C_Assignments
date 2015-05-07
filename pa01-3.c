/* Tony Hendrick, CIT 131, pa01-3 */
/*
*Calculates the total amount in a savings account
*where $100 is put in each month at 5% interest
*for six months.
*/

#include <stdio.h>

#define INTEREST_RATE 0.00417

int main( void )
{
    double savings_amount; /* input - the amount that is put into savings each month */
    double account_total; /* output - the total amount that is in savings after the interest rate */
    
    /* gets the amount that will be put into savings each month */
    printf("Enter the amount in $ that will be put into the account each month: ");
    scanf("%lf", &savings_amount);
    
    /* calculates the total amount is savings after six months */
    account_total = savings_amount * (1.0 + INTEREST_RATE);
    account_total = (savings_amount + account_total) * (1.0 + INTEREST_RATE);
    account_total = (savings_amount + account_total) * (1.0 + INTEREST_RATE);
    account_total = (savings_amount + account_total) * (1.0 + INTEREST_RATE);
    account_total = (savings_amount + account_total) * (1.0 + INTEREST_RATE);
    account_total = (savings_amount + account_total) * (1.0 + INTEREST_RATE);
    
    /* prints the total in the savings account after six months */
    printf("The total amount in the savings account after six months is: $ %.2f", account_total);
    
    return 0;
}
