/* Tony Hendrick, CIT 131, pa02-1 */
/* Uses two functions to display a triangle and rectangle */

#include <stdio.h>

/* Function that displays a rectangle */
void 
draw_rectangle(void)
{
    printf(" -----------\n");
    printf("|           |\n");
    printf("|           |\n");
    printf("|           |\n");
    printf(" -----------\n");
}

/* Function that displays a triangle */
void 
draw_triangle(void)
{
    printf("    /\\     \n");
    printf("   /  \\    \n");
    printf("  /    \\   \n");
    printf(" --------  \n");
}

int main(void)
{
    /* draw triangle */
    draw_triangle();
    /* draw rectangle */
    draw_rectangle();
    /* display two blank lines */
    printf("\n");
    printf("\n");
    /* draw triangle */
    draw_triangle();
    /* draw rectangle */
    draw_rectangle();
    
    return 0;
}


