/*
 * @file   pa09-38.c
 * @author Tony Hendrick
 * @version 3-31-15
 *
 * Program to learn how pointers, and pointers to pointers of type int work.
 * 
 * Improve: always set pointers to NULL during initialization
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * main function
 * @return EXIT_SUCCESS upon completion
 */
int main( void )
{
    //Declare int variables
    int a;
    int *x;
    int b;
    int *p;
    int **y;
    int c;
    int *q;
    int **r;
    int ***z;

    //Sets pointers x, p, and y
    x = &a;
    p = &b;
    y = &p;

    //Gets an int entered by the user and stores it in a
    printf("Enter a double to store in a: ");
    scanf("%i", x);

    //Gets an int entered by the user and stores it in b
    printf("Enter a double to store in b: ");
    scanf("%i", *y);

    //Sets pointers q, r, and z
    q = &c;
    r = &q;
    z = &r;

    //Multiplies int a and int b and stores it in int c using pointers
    ***z = *x * **y;

    //Prints out the variables using pointers
    printf("*x = %i", *x);
    printf("\n**y = %i",**y);
    printf("\n***z = %i",***z);

    //Exits program
    return (EXIT_SUCCESS);
}
