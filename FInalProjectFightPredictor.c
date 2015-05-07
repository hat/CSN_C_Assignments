/**
 * @file final.c
 * @author Tony Hendrick
 * @version 5-6-13
 *
 * Asks the user for the names of two fighters and then from user input
 * calculates each fighters winning percentage, knockout chance,
 * submission chance, and the favorite fighter win and the odds.
 * The program then runs a simulation 100 times to see which fighter
 * will win the fight is the two fighters were to face off against one
 * another. 
 * 
 * Credit to stackoverflow user Lukasz Lew for the random number generator
 *
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define TEST_FUNCTION // define for test run
#define BUF_SIZE 1024
#define SIM_TIMES 100
#define MAX_ODDS 1000

void getNames( char *name, int *timesRan );
void getFighterStats( void );
void getRecord( char *name, int *wins, int *losses );
double getWinPercentage( int *wins, int *losses, double *totalFights );
double getKOChance( char *fighterName, double *totalFights );
double getSubChance( char *fighterName, double *totalFights );
double getoddsOfWinning( char *fighterOne, char *fighterTwo, int *favoredFighter  );
void simulateFight( char *fighterOne, char *fighterTwo, double winPercentageOne, double winPercentageTwo, double fighterOneKOChance, double fighterTwoKOChance, double fighterOneSubChance, double fighterTwoSubChance, int *favoredFighter, double oddsOfWinning );
void simFight( char *fighterOne, char *fighterTwo, double fighterOneWinChance, double fighterTwoWinChance );
void printResults( char *fighterOne, char *fighterTwo, int *winnerFighterOne, int *winnerFighterTwo );

int main( void ){
    /* runs the function getFighterStats */
    getFighterStats(  );
    
}

/**
* The getNames function gets the name of a fighter from the user.
* @param *name where the user input will be stored
* @param *timesRan counts how many times the function has been called
*/
void getNames( char *name, int *timesRan ){
    
        long last; /* loop control variable */
        
        /* adds one each time the function is called */
        *timesRan += 1;
    
        /* Gets the user input for the name of the fighter */
        printf( "Enter the name of the  fighter #%i: ", *timesRan );
        fgets( name, BUF_SIZE, stdin );
        
        last = strlen(name) - 1;
        
        /* removes new line character from the inputted name */
        if( ( last >= 0 ) && ( name[last] == '\n' ) ){
            name[last] = '\0';
        }
        
        #ifdef TEST_FUNCTION
        printf( "Fighter %i's name is: %s\n", *timesRan, name );
        #endif
        
}

void getFighterStats( void ){
 
        char fighterOne[ BUF_SIZE ] = { '\0' }; /* Input - first fighter name */
        char fighterTwo[ BUF_SIZE ] = { '\0' }; /* Input - second fighter name */
        int timesGetNamesCalled = 0; /* counter for how many fighters have ben entered */
        int wins; /* Input - how many wins the fighter has */
        int losses; /* Input - how many losses the fighter has */
        double totalFights; /* Input - the total amount of fights the fighter has */
        double winPercentageOne; /* Output - the win percentage of the first fighter */
        double winPercentageTwo; /* Output - the win percentage of the second fighter */
        double fighterOneKOChance; /* Input - the ko chance of the first fighter */
        double fighterTwoKOChance; /* Input - the ko chance of the second fighter */
        double fighterOneSubChance; /* Input - the submission chance of the first fighter */
        double fighterTwoSubChance; /* Input - the submission chance of the second fighter */
        int favoredFighter; /* Input - the fighter who is favored */
        double oddsOfWinning; /* Output - the fighters chance to win */
        
        
        getNames( fighterOne, &timesGetNamesCalled ); /* get first fighter Ones name */
        getNames( fighterTwo, &timesGetNamesCalled ); /* get second fighter Twos name */
        
        getRecord( fighterOne, &wins, &losses ); /* gets fighter Ones record */
        winPercentageOne = getWinPercentage( &wins, &losses, &totalFights ); /* gets fighter Ones win percentage */
        fighterOneKOChance = getKOChance( fighterOne, &totalFights ); /* gets fighter Ones ko chance */
        fighterOneSubChance = getSubChance( fighterOne, &totalFights ); /* gets fighter Ones submission chance */
        
        getRecord( fighterTwo, &wins, &losses ); /* gets fighter Twos record */
        winPercentageTwo = getWinPercentage( &wins, &losses, &totalFights ); /* gets fighter Twos win percentage */
        fighterTwoKOChance = getKOChance( fighterTwo, &totalFights ); /* gets fighter Twos ko chance */
        fighterTwoSubChance = getSubChance( fighterTwo, &totalFights ); /* gets fighter Twos submission chance */
        
        oddsOfWinning = getoddsOfWinning( fighterOne, fighterTwo, &favoredFighter  ); /* gets the favored fighter and the odds */
        
        /* simulates the fight */
        simulateFight( fighterOne, fighterTwo, winPercentageOne, winPercentageTwo, fighterOneKOChance, fighterTwoKOChance, fighterOneSubChance, fighterTwoSubChance, &favoredFighter, oddsOfWinning );
}

/**
* The getRecord function gets the record of the fighter.
* @param *name the name of the fighter
* @param wins the amount of wins the fighter has
* @param losses the amount of losses the fighter has
*/
void getRecord( char *name, int *wins, int *losses ){
    
    int correctRecord = 0; /* loop variable */
    
    /* Loop to get the times the fighter has won and lost until correct */
    do{
        printf( "Enter how many times %s has won: ", name );
        scanf( "%i", wins );
    
        printf( "Enter how many times %s has lost: ", name );
        scanf( "%i", losses );
    
        printf( "Is this the correct record for %s: %i - %i (Enter 1 is correct): ", name, *wins, *losses );
        scanf( "%i", &correctRecord );
    } while ( correctRecord != 1 );
    
    #ifdef TEST_FUNCTION
    printf( "Record for %s: %i - %i\n", name, *wins, *losses );
    #endif
}

/**
* The getWinPercentage function calculates the fighters win percentage
* @param wins the amount of wins the fighter has
* @param losses the amount of losses the fighter has
* @param totalFights the total amount of fights the fighter has fought in
*/
double getWinPercentage( int *wins, int *losses, double *totalFights ){
    
    double winPercentage; /* the win percentage */
    
    *totalFights = *wins + *losses; /* calculates the total amount of fights */
    
    /* calculates the win percentage */
    winPercentage = ( (double) *wins / *totalFights);
    
    #ifdef TEST_FUNCTION
    printf( "The win percentage is: %lf\n", winPercentage );
    #endif
    
    return winPercentage; /* returns the win percentage */
}

/**
* The getKOChance function calculates the fighters knockout chance
* @param fighterName the name of the fighter
* @param totalFights the total amount of fights the fighter has fought in
*/
double getKOChance( char *fighterName, double *totalFights ){
    
    double knockout; /* the amount of knockouts */
    double koChance; /* the knockout chance percentage */
    int correct; /* loop variable */
    
    /* loop to get the number of KO's the fighter has until correct */
    do{
        printf( "Enter how many times %s has won by KO: ", fighterName );
        scanf( "%lf", &knockout );
    
        printf( "Is the correct number of KO's %s has:  %.0lf? (Enter 1 if correct): ", fighterName, knockout );
        scanf( "%i", &correct );
    } while ( correct != 1 );
    
    koChance = knockout / *totalFights; /* calculates knockout chance */
    
    #ifdef TEST_FUNCTION
    printf( "The KO percentage is: %lf\n", koChance );
    #endif
    
    return koChance; /* returns the knockout chance percentage */
    
}

/**
* The getSubPercentage function calculates the fighters submission percentage
* @param fighterName the fighters name
* @param totalFights the total amount of fights the fighter has fought in
*/
double getSubChance( char *fighterName, double *totalFights ){
    
    double submission; /* the amount of submissions */
    int correct; /* loop variable */
    double subChance; /* the chance of submissions */
    
    /* loop to get the submissio wins the fighter has until correct */
    do{
        printf( "Enter how many times has %s won by submission: ", fighterName );
        scanf( "%lf", &submission );
    
        printf( "Is the correct number of submissions %s has:  %.0lf? (Enter 1 if correct): ", fighterName, submission );
        scanf( "%i", &correct );
    } while ( correct != 1 );
    
    subChance = submission /  *totalFights; /* calculates the submission chance */

    #ifdef TEST_FUNCTION
    printf( "The submission percentage is: %lf\n", subChance );
    #endif
    
    return subChance; /* returns submission chance */
}

/**
* The getOddsOfWinning function gets the favorite and the odds of the favorite
* @param fighterOne the name of the first fighter
* @param fighterTwo the name of the second fighter
* @param favoredFighter what fighter is favored
*/
double getoddsOfWinning( char *fighterOne, char *fighterTwo, int *favoredFighter  ){
 
    double oddsOfWinning; /* the odds of winning  */
    int correct; /* loop variable */
    
    /* loop to get the odds of the favorite */
    do{
        printf( "Who is the favorite to win, Enter 1 if %s or Enter 2 if %s: ", fighterOne, fighterTwo );
        scanf( "%i", favoredFighter );
        
        if( *favoredFighter == 1 ){
            printf( "How much is %s favored by: (Ex: 250): ", fighterOne );
            scanf( "%lf", &oddsOfWinning );
            printf( "%s is favored by %lf (Enter 1 if correct): ", fighterOne, oddsOfWinning );
            scanf( "%i", &correct );
        } else {
            printf( "How much is %s favored by: (100-1000): ", fighterTwo );
            scanf( "%lf", &oddsOfWinning );
            printf( "%s is favored by %lf (Enter 1 if correct): ", fighterTwo, oddsOfWinning );
            scanf( "%i", &correct );
        }

    } while ( correct != 1 );
    
    #ifdef TEST_FUNCTION
    printf( "Fighter %i is favored by %lf.\n", *favoredFighter, oddsOfWinning );
    #endif
    
    return oddsOfWinning; /* returns the odds of the favorite */
}

/**
* The simulateFight function simulates the fight based on the previously entered data
* @param fighterOne the name of the first fighter
* @param fighterTwo the name of the second fighter
* @param winPercentageOne the first fighters win percentage
* @param winPercentageOne the second fighters win percentage
* @param fighterOneKOChance the first fighters knockout chance
* @param fighterTwoKOChance the second fighters knockout chance
* @param fighterOneSubChance the first fighters submission chance
* @param fighterTwoSubChance the second fighters submission chance
* @param favoredFighter the fighter who is favored
* @param oddsOfWinning the odds of the favorite winning
*/
void simulateFight( char *fighterOne, char *fighterTwo, double winPercentageOne, double winPercentageTwo, double fighterOneKOChance, double fighterTwoKOChance, double fighterOneSubChance, double fighterTwoSubChance, int *favoredFighter, double oddsOfWinning ){
    
    double fighterOneWinChance; /* the percentage the first fighter wins */
    double fighterTwoWinChance; /* the percentage the second fighter wins */
    
    /* makes each variable 1/4 of the total */
    winPercentageOne *= .25;
    winPercentageTwo *= .25;
    fighterOneKOChance *= .25;
    fighterTwoKOChance *= .25;
    fighterOneSubChance *= .25;
    fighterTwoSubChance *= .25;
    oddsOfWinning *= .25 / MAX_ODDS;
    
    /* gets each fighters chance of winning */
    fighterOneWinChance = winPercentageOne + fighterOneKOChance + fighterOneSubChance;
    fighterTwoWinChance = winPercentageTwo + fighterTwoKOChance + fighterTwoSubChance;
    
    /* adds the odds to the chance of winning for the favorite */
    if( *favoredFighter == 1 ){
        fighterOneWinChance += oddsOfWinning;
    } else {
        fighterTwoWinChance += oddsOfWinning;
    }
     
    #ifdef TEST_FUNCTION
    printf( "%s has a %lf chance of winning.\n", fighterOne, fighterOneWinChance );
    printf( "%s has a %lf chance of winning.\n", fighterTwo, fighterTwoWinChance );
    #endif
    
    /* calls the simFight function */
    simFight( fighterOne, fighterTwo, fighterOneWinChance, fighterTwoWinChance );
}

/**
* The simulateFight function simulates the fight based on the previously entered data
* @param fighterOne the name of the first fighter
* @param fighterTwo the name of the second fighter
* @param fighterOneWinChance the chance of the first fighter winning
* @param fighterTwoWinChance the chance of the second fighter winning
*/
void simFight( char *fighterOne, char *fighterTwo, double fighterOneWinChance, double fighterTwoWinChance ){
    
    int fighterOneWin[SIM_TIMES] = { 0 }; /* array to store if fighter one won */
    int fighterTwoWin[SIM_TIMES] = { 0 }; /* array to store if fighter two won */
    int *fighterOneSuccess = 0; /* the amount of times fighter one won */
    int *fighterTwoSuccess = 0; /* the amount of times fighter two won */
    int i; /* loop contol variable */
    int r; /* random number */
    
    /* uses the time to get the random number */
    srand(time(NULL));
    
    fighterOneWinChance *= 100;
    fighterTwoWinChance *= 100;
    
    /* gets a random number and checks to see if it falls between fighter ones win chance */
    for( i = 0; i < SIM_TIMES; i++ ){
        r = rand() % 100;
        if( r <= (int)fighterOneWinChance ){
            fighterOneWin[i]++;
        }
    }
    
    /* adds one every time the random number fell between fighter ones win chance */
    for( i = 0; i < SIM_TIMES; i++ ){
        if( fighterOneWin[i] > 0 ){
            fighterOneSuccess++;
        }
    }
    
    /* gets a random number and checks to see if it falls between fighter twos win chance */
    for( i = 0; i < SIM_TIMES; i++ ){
        r = rand() % 100;
        if( r <= (int)fighterTwoWinChance ){
            fighterTwoWin[i]++;
        }
    }
    
    /* adds one every time the random number fell between fighter twos win chance */
    for( i = 0; i < SIM_TIMES; i++ ){
        if( fighterTwoWin[i] > 0 ){
            fighterTwoSuccess++;
        }
    }
    
    /* calls the function to print the results */
    printResults( fighterOne, fighterTwo, fighterOneSuccess, fighterTwoSuccess );
    
    #ifdef TEST_FUNCTION
    printf( "Fighter number one won %i times.\n", *fighterOneSuccess );
    printf( "Fighter number two won %i times.\n", *fighterTwoSuccess );
    #endif
}

/**
* The simulateFight function simulates the fight based on the previously entered data
* @param fighterOne the name of the first fighter
* @param fighterTwo the name of the second fighter
* @param winnerFighterOne the amount of times fighter one won
* @param winnerFighterTwo the amount of times fighter two won
*/
void printResults( char *fighterOne, char *fighterTwo, int *winnerFighterOne, int *winnerFighterTwo ){
 
    puts( "" );
    puts( "" );
    printf( "The winner of %s versus %s is...\n", fighterOne, fighterTwo );
    
    /* prints who won the fight */
    if( winnerFighterOne > winnerFighterTwo ){
        printf( "%s!\n", fighterOne );
    } else {
        printf( "%s!\n", fighterTwo );
    }
    
}
