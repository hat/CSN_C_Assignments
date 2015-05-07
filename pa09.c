/**
 * @file pa09.c
 * @author Tony Hendrick
 * @version 4-22-13
 *
 * Takes a file with the number of years to be used first followed by
 * the rainfall for each month in the year for a specific city and
 * displays the total rainfall, the average monthly rainfall, the
 * month with the largest rainfall, the month with the smallest rainfall,
 * and the rainfall of every month sorted in ascending order.
 *
*/

#include <stdio.h>
#include <stdlib.h>

/* preprocessor macro definitions */
#define MONTHS 12
#define MAX_MONTH_LETTERS 9

/* function prototypes */
void readRainfall( FILE *inf, double rainfall[], int size );
int getMonthSmallest( double rainfall[], int size );
int getMonthLargest( double rainfall[], int size );
double totalRainfall( double rainfall[], int size );
double averageRainfall( double total, int size );
void sortAscending( double rainfall[], int size );
void outputData( int i, double total, double rainfall[], double average, int monthSmallest, int monthLargest );
void printMonth( int month );

/* main function
 * @return An integer representing success or failure
*/
int main( void )
{

    int status = EXIT_SUCCESS; /* exit code to return to the OS */
    FILE *inf = fopen( "/home/shared/rainfall2.txt", "r" ); /* file to read the data from */

    /* checks if file opened correctly */
    if( inf ) {

        double rainfall[MONTHS] = {0}; /* input: array with rainfall of each month */
        int dataSets = 0; /* input: the number of years */
        int i = 0; /* control variable */
        int monthSmallest; /* input: the smallest month in int form */
        int monthLargest; /* input: the largest month in int form */
        double total; /* input: the sum off all the rainfall from each month */
        double average; /* input: the average rainfall of the year */

        /* scans the file for the first int which indicates the number of years */
        fscanf( inf, "%i", &dataSets );

        /* loop continues until number of years is met */
        for( i = 0; i < dataSets; i++ ) {

            /* calls functions */
            sortAscending( rainfall, MONTHS );
            readRainfall( inf, rainfall, MONTHS );
            monthSmallest = getMonthSmallest( rainfall, MONTHS );
            monthLargest = getMonthLargest( rainfall, MONTHS );
            total =  totalRainfall( rainfall, MONTHS );
            average =  averageRainfall( total, MONTHS );
            sortAscending( rainfall, MONTHS );
            outputData( i, total, rainfall, average, monthSmallest, monthLargest );

        }

        /* sets status to failure */
    } else {

        fprintf( stderr, "Cannot open data file.\n" );
        status = EXIT_FAILURE;

    }

    return status;

}

/**
* The readRainfall function reads the rainfall for each month from
* the file.
* @param *inf The file to be read from
* @param rainfall[] The array holding each months rainfall amount
* @param size The size of the rainfall array
*/
void readRainfall( FILE *inf, double rainfall[], int size )
{

    int i = 0; /* counter variable */

    /* loop that goes through all 12 months */
    for( i = 0; i < size; i++ ) {

        /* Scans the data from the file */
        fscanf( inf, "%lf", &rainfall[i] );

    }

}

/**
* The getMonthSmallest function returns the month with the smallest
* amount of rainfall in integer form
* @param rainfall[] The array holding each months rainfall amount
* @param size The size of the rainfall array
*/
int getMonthSmallest( double rainfall[], int size )
{

    int smallestMonth = 0; /* the integer representing the smallest month */
    int i = 0; /* control variable */
    double temp = rainfall[0]; /* holds the smallest amount of rainfall */

    /* loop that runs through the 12 months */
    for( i = 0; i < size; i++ ) {

        /* changes the month if it finds a month with a smaller amount of rainfall */
        if( rainfall[i] <  rainfall[i + 1] && rainfall[i] < temp ) {
            temp = rainfall[i];
            smallestMonth = i;
        }

    }

    /* returns the smallest month in integer form */
    return smallestMonth;

}

/**
* The getMonthLargest function returns the month with the largest
* amount of rainfall in integer form
* @param rainfall[] The array holding each months rainfall amount
* @param size The size of the rainfall array
*/
int getMonthLargest( double rainfall[], int size )
{

    int largestMonth = 0; /* The largest month in integer form */
    int i = 0; /* control variable */
    double temp = rainfall[0]; /* The rainfall from each month */

    /* loop that runs through the 12 months */
    for( i = 0; i < size; i++ ) {

        /* changes the month if it finds a month with a largest amount of rainfall */
        if( rainfall[i] >  rainfall[i + 1] && rainfall[i] > temp ) {
            temp = rainfall[i];
            largestMonth = i;
        }

    }

    /* returns the month with the most amount of rainfall in integer form */
    return largestMonth;

}

/**
* The totalRainfall function returns the total amount of rainfall
* of the year
* @param rainfall[] The array holding each months rainfall amount
* @param size The size of the rainfall array
*/
double totalRainfall( double rainfall[], int size )
{

    double total = 0; /* The total amount of rainfall */
    int i = 0; /* control variable */

    /* loop that goes through the 12 months */
    for( i = 0; i < size; i++ ) {

        /* adds all the rainfall from each month together */
        total = total + rainfall[i];

    }

    /* returns the total amount of rainfall */
    return total;

}

/**
* The averageRainfall function returns the average amount of rainfall
* of the year
* @param total The total amount of rainfall of the year
* @param size The amount of months in a year
*/
double averageRainfall( double total, int size )
{

    double average = 0; /* The average amount of rainfall */

    /* calculate the average */
    average = total / size;

    /* returns the average */
    return average;

}

/**
* The sortAscending function sorts the rainfall in ascending order
* @param rainfall[] The array holding each months rainfall amount
* @param size The size of the rainfall array
*/
void sortAscending( double rainfall[], int size )
{

    int i = 0; /* control variable */
    int j = 0; /* control variable */
    int current; /* the current position of the rainfall amount */
    double swap; /* the amount of rainfall to be swapped */

    /* lop that goes through the 12 months */
    for ( i = 0 ; i < size ; i++ ) {
        current = i; /* sets current to i */

        /* loop that runs through the 12 months */
        for ( j = i + 1 ; j < size ; j++ ) {
            /* sets current to j if the current one is larger than the next */
            if ( rainfall[current] > rainfall[j] )
                current = j;
        }
        /* if the current is not the smallest it swaps the amounts */
        if ( current != i ) {
            swap = rainfall[i];
            rainfall[i] = rainfall[current];
            rainfall[current] = swap;
        }
    }
}

/**
* The printMonth function takes the integer that represents a month
* and prints the month.
* @param month The integer representing a month
*/
void printMonth( int month )
{

    /* switch statement to print the month based on the integer given */
    switch( month ) {

    case 0:
        puts("January.");
        break;
    case 1:
        puts("February.");
        break;
    case 2:
        puts("March.");
        break;
    case 3:
        puts("April.");
        break;
    case 4:
        puts("May.");
        break;
    case 5:
        puts("June.");
        break;
    case 6:
        puts("July.");
        break;
    case 7:
        puts("August.");
        break;
    case 8:
        puts("September.");
        break;
    case 9:
        puts("October.");
        break;
    case 10:
        puts("November.");
        break;
    case 11:
        puts("December.");
        break;

    }

}

/**
* The outputData function prints all of the data that was acquired from
* all the previous functions
* @param i The number of sets (years)
* @param total The total amount of rainfall
* @param rainfall The array holding all the rainfall from each month
* @param average The average amount of rainfall from the year
* @param monthSmallest The month with the smallest amount of rainfall
*        in integer form
* @param monthLargest The month with the largest amount of rainfall
*        in integer form
*/
void outputData( int i, double total, double rainfall[], double average, int monthSmallest, int monthLargest )
{

    int j = 0; /* control variable */
    int setNumber = i + 1; /* keeps count of the how many years of data are being processed */

    /* prints the data */
    printf( "Set #%i\n", setNumber );
    printf( "The total rainfall for the year is %.2f inches.\n", total );
    printf( "The average monthly rainfall for the year is %.2f inches.\n", average );
    printf( "The largest monthly rainfall was %.2f inches in ", rainfall[11] );
    printMonth( monthLargest );
    printf( "The smallest monthly rainfall was %.2f inches in ", rainfall[0] );
    printMonth( monthSmallest );

    puts("");

    puts( "Here are the rainfall amounts, sorted in ascending order:" );
    puts( "---------------------------------------------------------" );

    for( j = 0; j < MONTHS; j++ ) {
        printf( "%.2f\n", rainfall[j] );
    }
    puts("");

}
