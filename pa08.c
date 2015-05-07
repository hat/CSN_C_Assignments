/**
 * @file pa08.c
 * @author Tony Hendrick
 * @version 4-15-11
 * Creates a magic square that is between the size of 3 X 3 and 9 X 9
 * and calculates the sum of each row, column, and diagonal.
 * 
 * NOTE: to rotate 90 degrees try to not use a new array
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* preprocessor macro definitions */
#define ROW_NUMS 19
#define COL_NUMS 19

/* function prototypes */
void sortNumbers( int squareArray[][COL_NUMS],  int sizeSquare );
void printSquare( int squareArray[][COL_NUMS], int sizeSquare );
void rotateSquare90( int transposeSquareArray[][COL_NUMS], int squareArray[][COL_NUMS], int sizeSquare );

/* main function
 * @return An integer value indicating success or failure
 */
int main( void ){
    
    int status = EXIT_SUCCESS; /* exit code to return to OS */
    int sizeSquare; /* input: size of one side of the square */
    int squareArray[COL_NUMS][ROW_NUMS] = { {0} }; /* output: the magic square */
    int transposeSquareArray[COL_NUMS][ROW_NUMS] = { {0} }; /* output: the magic square */
    int rotateSquare = 0; /* checks whether to rotate or not, currently false */
      
    /* asks the user to input an integer until it is odd and between 3-9 */  
    do{
        
        printf( "Enter an ODD number between 3-19: "  );
        scanf( "%i", &sizeSquare );
        
    } while( sizeSquare % 2 == 0 || sizeSquare < 3 || sizeSquare > 19 );
    
    /* checks again to make sure the user input is odd and between 3-9 */
    if( sizeSquare % 2 != 0 && sizeSquare >= 3 && sizeSquare <= 19 ){
        
        /* calls two functions */
        sortNumbers( squareArray, sizeSquare );
        printSquare( squareArray, sizeSquare );
    
        /* checks to see whether to rotate the magic square */
        printf( "Enter 1 to rotate the magic square to the right 90 degrees (0 to exit): " );
        scanf( "%i", &rotateSquare );
         
        /* checks to see if the user wants the square rotated */
        if( rotateSquare == 1 ){
            /* calls the rotateSquare90 function */
            rotateSquare90( transposeSquareArray, squareArray, sizeSquare );
        }
    
    /* sets status to failure */
    } else {
        puts( "The number entered does not meet the requirements." );
        status = EXIT_FAILURE;
    }
    
    return status;
    
}

/**
* The sortNumbers function sorts the numbers 1 through the total number
* of boxes in the magic square in the correct place.
* @param squareArray[][] A two-dimensional array to hold the numbers
* @param sizeSquare The size of one side of the square
*/
void sortNumbers( int squareArray[][COL_NUMS], int sizeSquare  ) {

    int row; /* the current row of the square */
    int col; /* the current column of the square */
    int new_row; /* the row to change to */
    int new_col; /* the column to change to */
    int max; /* the number of boxes in the square */
    int i; /* control for loop */
    
    row = 0; /* sets the row to start at 0 */
    col = sizeSquare / 2; /* sets the column to start in the middle of the magic square */
    max = sizeSquare * sizeSquare; /* sets max to the product of sizeSquare times sizeSquare */
    
    squareArray[row][col] = 1; /* puts 1 in the current row and column */
    
    /* a loop that goes through until max is reached */
    for ( i = 2; i < max + 1; i++ ) {
        /* checks to see if going up a row leads to out of bounds */
        if ( (row - 1) < 0 ) {
            new_row = sizeSquare - 1;
        } else {
            new_row = row - 1; 
        }

        /* checks to see if going right a column leads out of bounds */
        if ( (col + 1) > (sizeSquare - 1) ) {
            new_col = 0;                                 
        } else {
            new_col = col + 1;
        }                                                                

        /* checks to see if the current box selected has been used already */
        if ( squareArray[new_row][new_col] > 0) {        
            if ( row > (sizeSquare - 1) ) {          
                new_row = 0;                             
            }                                                                     
            else {                                                                
                new_row = row + 1;                       
                new_col = col;                       
            }                                                                     
        }   
        
        row = new_row;  /* sets row equal to the new row */                                                        
        col = new_col;  /* sets column to the new column */                                     
    squareArray[row][col] = i; /* places the next number in the current box */        
    }  
    
}

/**
* The printSquare function prints the squareArray and calculates as well
* as prints the sum of any row, column, or diagonal of the magic square.
* @param squareArray[][] A two-dimensional array to hold the numbers
* @param sizeSquare The size of one side of the square
*/
void printSquare( int squareArray[][COL_NUMS], int sizeSquare ){
    
    int i; /* control for loop */
    int j; /* control for loop */
    int sum; /* the sum of the magic square going vertical, horizontal, or diagonal */
    
    /* calculates the sum */
    sum = ((int) pow(sizeSquare, 3) + sizeSquare) / (2);
    
    /* prints the sum */
    printf("The sum of any row, column, or diagonal is %i\n", sum);

    /* loop to print the magic square */
    for (i = 0; i < sizeSquare; i++) {                                                     
        for (j = 0; j < sizeSquare; j++) {                                                 
            printf("%4i", squareArray[i][j]);                                           
        }                                                                         
        printf("\n");                                                             
    } 
}

/**
* The rotateSquare90 function takes the squareArray
* and rotates it 90 degrees to the right.
* @param transposeSquareArray[][] the rotated squareArray
* @param squareArray[][] A two-dimensional array to hold the numbers
* @param sizeSquare The size of one side of the square
*/
void rotateSquare90( int transposeSquareArray[][COL_NUMS], int squareArray[][COL_NUMS], int sizeSquare ){
    
    int i; /* control for loop */
    int j; /* control for loop */
    int temp; /* temporary holder */
    
    /* switches the rows and columns of squareArray and stores it in transposeSquareArray */
    for (i = 0; i < sizeSquare; i++) {                                                     
        for (j = 0; j < sizeSquare; j++) {                                                 
            transposeSquareArray[j][i] = squareArray[i][j];                                        
        }
    } 
    
    /* reverses each row of the transposeSquareArray */
    for( j = 0; j < sizeSquare; j++){
        for( i = 0; i < sizeSquare / 2; i++) {
            temp = transposeSquareArray[j][i];
            transposeSquareArray[j][i] = transposeSquareArray[j][sizeSquare - i - 1];
            transposeSquareArray[j][sizeSquare - i - 1] = temp;
        }
    }
    
    /* prints new line */
    putchar('\n'); 
    
    /* loop to print the rotated magic square */
    for (i = 0; i < sizeSquare; i++) {                                                     
        for (j = 0; j < sizeSquare; j++) {                                                
            printf("%4i", transposeSquareArray[i][j]);                                           
        }                                                                         
        printf("\n");                                                             
    } 
}

