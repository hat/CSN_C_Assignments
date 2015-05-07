/*
 * @file pa06.c
 * @author Tony Hendrick
 * @version 4-1-2014
 * Takes a text file with operators and operands and acts as
 * a simple calculator
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

/* declares functions */
void scan_data( FILE *in_file, char *op, double *operand );
void do_next_op( char op, double *operand1, double operand2 );

int main( void )
{
    FILE *in_file = NULL; /* Input - text file */
    char operator; /* Input - operator */
    double operand_scan; /* Input - operand */
    double operand; /* Input/Output - the left operand */

    /* opens the text file */
    in_file = fopen( "/home/shared/data.txt", "r" );

    /* loop to keep going until the file ends */
    do {
        /* calls functions */
        scan_data( in_file, &operator, &operand_scan );
        do_next_op( operator, &operand, operand_scan );

    } while( operator != 'Q' );

    /* closes file */
    fclose( in_file );

    return ( 0 );

}

/*
 * the scan_data function. This function accepts as its parameters a
 * pointer to the input file, a pointer to the char for the operator,
 * and a pointer to a double for the operand.
 * @param in_file The input file to read. Assumed to be opened.
 * @param op An output parameter for storing the operator character.
 * @param operand An output parameter for storing the operand.
*/
void scan_data( FILE *in_file, char *op, double *operand )
{
    /* declares local variables */
    char op_in;
    double operand_in;

    /* scans the file for the next character */
    fscanf( in_file, " %c", &op_in );
    /* sets operator to the character scanned */
    *op = toupper( op_in );

    /* scans the file for the next double */
    fscanf( in_file, " %lf", &operand_in );
    /* sets the operand to the double scanned */
    *operand = operand_in;
}

/*
 * the do_next_op function. This function performs the operation
 * specified by the op character.
 * @param op The operator.
 * @param operand1 An input/output parameter representing the left
 *  operand.
 * @param operand2 The right operand.
 */
void do_next_op( char op, double *operand1, double operand2 )
{
    /* switch case based on the operator.
    * performs calculation based off operator.
    * prints the operator and both operands after execution.
    */
    switch( op ) {
    case '+':
        *operand1 = *operand1 + operand2;
        printf( "%c %g\n", op, operand2 );
        printf( "= %g\n", *operand1 );
        puts( "\n" );
        break;
    case '-':
        *operand1 = *operand1 - operand2;
        printf( "%c %g\n", op, operand2 );
        printf( "= %g\n", *operand1 );
        puts( "\n" );
        break;
    case '*':
        *operand1 = *operand1 * operand2;
        printf( "%c %g\n", op, operand2 );
        printf( "= %g\n", *operand1 );
        puts( "\n" );
        break;
    case '/':
        /* checks to see if division by zero */
        if( operand2 != 0 ) {
            *operand1 = *operand1 / operand2;
            printf( "%c %g\n", op, operand2 );
            printf( "= %g\n", *operand1 );
            puts( "\n" );
        } else {
            puts( "Error: division by zero." );
            printf( "%c %g \n", op, operand2 );
            printf( "= %g", *operand1 );
            puts( "\n" );
        }
        break;
    case '^':
        *operand1 = pow( *operand1, operand2 );
        printf( "%c %g\n", op, operand2 );
        printf( "= %g\n", *operand1 );
        puts( "\n" );
        break;
    case 'S':
        *operand1 = operand2;
        printf( "%c %g\n", op, operand2 );
        printf( "= %g\n", *operand1 );
        puts( "\n" );
        break;
    case 'Q':
        puts( "Done.\n" );
        puts( "\n" );
        break;
    default:
        printf( "Error: invalid operator \'%c\'\n", op );
        printf( "%c %g \n", op, operand2 );
        printf( "= %g", *operand1 );
        puts( "\n" );
    }
}
