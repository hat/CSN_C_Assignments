/*
 * @file pa05.c
 * @author Tony Hendrick
 * @version 3-25-2014
 * Decodes a given text file that contains integers.
 * CORRECTION: should have checked mode in function with two parameters
 * in functions/function.
 */

#include <stdio.h>

/* Declares Constants */
#define UPPERCASE 0
#define LOWERCASE 1
#define PUNCTUATION 2

/* Declares Functions */
int upperCase( int code );
int lowerCase( int code );
int punctuation( int code );

int main( void )
{
    int coded_message; /* Input - text file */
    int code; /* Input - the next integer in the text file */
    int mode; /* Input - decides which function to run */
    
    /* Sets mode and scans first integer from text file */
    mode = UPPERCASE;
    coded_message = scanf( "%i", &code );
    
    /* Loop that continues until the end of the file */
    while ( coded_message != EOF ){
        
        /* Runs the upperCase function */
        if ( mode == UPPERCASE ){
            upperCase( code );
        }
        /* Runs the lowerCase function */
        if ( mode == LOWERCASE ){
            lowerCase( code );
        }
        /* Runs the punctuation function */
        if ( mode == PUNCTUATION ){
            punctuation( code );
        }
        
        /* Changes the mode */
        if( upperCase( code ) == 0 ){
            
            mode = mode + 1;
        }
        if( lowerCase( code ) == 0 ){
            mode = mode + 1;
        }
        if( punctuation( code ) == 0 ){
            mode = mode - 2;
        }
        
        /* Scans the text file for the next integer */
        coded_message = scanf( "%i", &code );

    }
    
    return 0;
}

/* Prints an uppercase character */
int upperCase( int code ){
    
    int decoded_message; /* Output - the decoded character */

    decoded_message = code % 27;
    
    /* Prints an uppercase character */
    if( decoded_message !=0 ){
        decoded_message = decoded_message + 64;
        printf( "%c", decoded_message );
    }
    
    return decoded_message;
}

int lowerCase( int code ){
    
    int decoded_message; /* Output - the decoded character */
    
    decoded_message = code % 27;
    
    /* Prints a lowercase character */
    if( decoded_message !=0 ){
        decoded_message = decoded_message + 96;
        printf( "%c", decoded_message );
    }
    
    return decoded_message;
}

int punctuation( int code ){
    
    int decoded_message; /* Output - the decoded character */
    
    decoded_message = code % 9;
    
    /* Switch statement to print the corresponding punctuation mark */
    if( decoded_message !=0 ){
        switch( decoded_message ){
            case 1:
                printf( "!" );
                break;
            case 2:
                printf( "?" );
                break;
            case 3:
                printf( "," );
                break;
            case 4:
                printf( "." );
                break;
            case 5:
                printf( " " );
                break;
            case 6:
                printf( ";" );
                break;
            case 7:
                printf( "\"" );
                break;
            case 8:
                printf( "\'" );
                break;
            default:
                puts( "ERROR" );
        }
    }
    
    return decoded_message;
}


