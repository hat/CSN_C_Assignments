/**
 * @file pa07.c
 * @author Tony Hendrick
 * @version 4-9-11
 * Takes a file that contains integers between 1 and 100 and then
 * displays how many times each number appeared
 * 
 * Error: loops in functions should run until file ends with 0
 *   ( do{}while(num_file != 0)
 * 
 * Note: Start array at index 1 instead of 0
 */

#define NDEBUG         /* comment out this line to deactivate assert */
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>

/* preprocessor macro definitions */
#define NUMBER_ELEMENTS 100

/* function prototypes */
void countValues( FILE *inf, int list[], int size );
void printFrequencies( const int list[], int size );

/* main function
 * @return An integer value indicating success or failure
 */
int main( void )
{

    int status = EXIT_SUCCESS; /* exit code to return to OS */
    FILE *inf = fopen( "/home/shared/numbers2.txt", "r" ); /* input data file */

    /* checks to see if the file has been found and opened */
    if( inf ) {

        int list[NUMBER_ELEMENTS] = {0}; /* output accumulator array for numbers */

        /* calls functions */
        countValues( inf, list, NUMBER_ELEMENTS );
        printFrequencies( list, NUMBER_ELEMENTS );

        /* closes file and sets pointer variable to NULL */
        fclose( inf );
        inf = NULL;

        /* sets status to failure and prints error message */
    } else {
        fprintf( stderr, "Cannot open data file.\n" );
        status = EXIT_FAILURE;
    }

    return status;

}

/**
* The countValues function reads integers from a file and tallies the
* number of times each integer appears in the file.
* The input file must already be open prior to calling this function
* or an assertion will be generated. The integer array parameter is
* assumed to be initialized prior to invoking
* this function.
* @param inf A pointer to the open file.
* @param list[] An array of integers.
* @param size The size of the integer array parameter.
*/
void countValues( FILE *inf, int list[], int size )
{

    int num_file; /* input - the number from the file */
    int i; /* control for loop */

    /* sets variable to zero */
    num_file = 0;

    /* reads the file and counts the number that is read from the file */
    /*for( i = 0; i < size; i++ ) {*/
     do{
        fscanf( inf, "%i", &num_file );
        list[num_file]++;
        } while ( &num_file != 0 )

}

/**
* The printFrequencies function displays the frequency (number of
* occurrences) of each integer value in an array.
* If the frequency is 0, nothing is printed.
* @param list An array of integers.
* @param size The size of the integer array parameter.
*/
void printFrequencies( const int list[], int size )
{

    int i; /* control for loop */

    /* prints the number of times each number appeared that is non zero */
    for( i = 1; i < size; i++ ) {
        if( list[i] == 1 ) {
            printf( "%i occurs %i time\n", i, list[i] );
        } else if ( list[i] > 1 ) {
            printf( "%i occurs %i times\n", i, list[i] );
        }
    }
}
