/*
 * @file   pa09-36.c
 * @author Tony Hendrick
 * @version 3-31-15
 *
 * Program to learn how pointers to pointers work
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
    int *p;
    int **q;
    int **r;
    int ***s;
    int ***t;
    int ***u;
    int ***v;

    //Get an integer from the user
    printf("Enter an integer: ");
    scanf("%i", &a);

    //Set the pointers p, q, r, s, t, u, v
    p = &a;
    q = &p;
    r = q;
    s = &r;
    t = s;
    u = s;
    v = s;

    //Print out int a using pointers p, q, r, s, t, u, v
    printf("*p = %i", *p);
    printf("\n**q = %i", **q);
    printf("\n**r = %i", **r);
    printf("\n***s = %i", ***s);
    printf("\n***t = %i", ***t);
    printf("\n***u = %i", ***u);
    printf("\n***v = %i", ***v);

    //Exit program
    return (EXIT_SUCCESS);
}
