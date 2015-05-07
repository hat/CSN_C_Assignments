/* Tony Hendrick, CIT 131, pa03-1 */
/* Reads in five values that represent the monthly amount
 * spent on the following budget categories: 
 * food, clothing, transportation, entertainment, and rent. 
 * Then, displays a bar graph showing these values.
 */

#include <stdio.h>
#include <graphics.h>

/* declares function barGraph */
void barGraph( int x1, int activity, int x2, int y, int color );

int main( void )
{
        int gd = DETECT; /* graphic driver */
        int gm = VGAMAX; /* graphics mode */
        
        int maxX; /* width of graphics window */
        int maxY; /* height of graphics window */
        int centerX; /* horizontal center of window */
        int centerY; /* vertical center of window */
        
        int food; /* Input- the amount spent on food for the month */
        int clothing; /* Input- the amount spent on clothing for the month */
        int transportation; /* Input- the amount spent on transportation for the month */
        int entertainment; /* Input- the amount spent on entertainment for the month */
        int rent; /* Input- the amount spent on rent for the month */
        
        /* Sets the points used for the bar graphs and text */
        int y;
        int x1; int x2;
        int x3; int x4;
        int x5; int x6;
        int x7; int x8;
        int x9; int x10;
        
        /* Asks the user how much they spent on each activity and stores the answer */
        printf("How much in dollars was spent this month on food? Up to $2000: ");
        scanf("%i", &food);
        
        printf("How much was spent in dollars this month on clothing? Up to $2000: ");
        scanf("%i", &clothing);
        
        printf("How much was spent in dollars this month on transportation? Up to $2000: ");
        scanf("%i", &transportation);
        
        printf("How much was spent in dollars this month on entertainment? Up to $2000: ");
        scanf("%i", &entertainment);
        
        printf("How much was spent in dollars this month on rent? Up to $2000: ");
        scanf("%i", &rent);
        
        /* start the graphics mode */
        initgraph( &gd, &gm, NULL );
        
        /* get the largest values for x and y */
        maxX = getmaxx();
        maxY = getmaxy();
        
        /* find the center of the window */
        centerX = maxX / 2;
        centerY = maxY / 2;
        
        /* finds the points for the bar graph and text */
        y = (maxY * .90);
        x1 = (maxX * 3 / 20);  x2 = (maxX * 5 / 20);
        x3 = (maxX * 6 / 20); x4 = (maxX * 8 / 20);
        x5 = (maxX * 9 / 20); x6 = (maxX * 11 / 20);
        x7 = (maxX * 12 / 20); x8 = (maxX * 14 / 20);
        x9 = (maxX * 15 / 20); x10 = (maxX * 17 / 20);
        
        /* calls the function bar graph for every activity */
        barGraph( x1, (food / 5.8), x2, y, 1 );
        barGraph( x3, (clothing / 5.8), x4, y, 2 );
        barGraph( x5, (transportation / 5.8), x6, y, 3 );
        barGraph( x7, (entertainment / 5.8), x8, y, 4 );
        barGraph( x9, (rent / 5.8), x10, y, 5 );
        
        /* sets color to white */
        setcolor( 15 );
        
        /* prints labels under the bars in the bar graph */
        outtextxy(x1, 460, "FOOD");
        outtextxy(x3, 460, "CLOTHING");
        outtextxy(x5, 460, "TRANS.");
        outtextxy(x7, 460, "ENTMT.");
        outtextxy(x9, 460, "RENT");
        
        /* prints lines on the bar graph for easier reading */
        line((maxX * .1), (maxY* .18), (maxX * .9), (maxY * .18));
        line((maxX * .1), (maxY* .36), (maxX * .9), (maxY * .36));
        line((maxX * .1), (maxY* .54), (maxX * .9), (maxY * .54));
        line((maxX * .1), (maxY* .72), (maxX * .9), (maxY * .72));
        line((maxX * .1), (maxY* .90), (maxX * .9), (maxY * .90));
        
        /* prints dollar amounts for each line for easier reading */
        outtextxy((maxX * .05), (maxY * .18), "$2000");
        outtextxy((maxX * .05), (maxY * .36), "$1500");
        outtextxy((maxX * .05), (maxY * .54), "$1000");
        outtextxy((maxX * .05), (maxY * .72), "$500");
        outtextxy((maxX * .05), (maxY * .90), "$0");
        
        /* pause to view graphics window */
        getch();
        
        /* shut down the graphics window */
        closegraph();
        
        return 0;

}

/* function that draws bars in bar graph */
void barGraph( int x1, int activity, int x2, int y, int color )
{
    /* sets the outline color of the bar */
    setcolor( color );
    
    /* draws the bar */
    rectangle(x1,(y - (activity)), x2, y );
    
    /* fills the bar with color */
    floodfill( (x2-1), (y-1), color );
}
