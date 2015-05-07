/*
 * @file pa12.c
 * @author Tony Hendrick
 *
 * This program simulates a poker game dealing 5 hands and then seeing if
 * those hands contain a pair, two pair, three of a kind, four of a kind,
 * flush, or straight.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//enum Suit to hold the suits in a deck of cards
typedef enum Suit {
    CLUB = 1,
    DIAMOND,
    HEART,
    SPADE,
    SUIT_SIZE = 5
} Suit;

//enum Rank to hold the ranks of cards in a deck of cards
typedef enum Rank {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    RANK_SIZE = 14
} Rank;

//struct Card to hold a card that has a suit and rank
typedef struct {
    Suit suit;
    Rank rank;
} Card;

//struct Deck to hold 52 cards
typedef struct {
    Card deckCard[52];
} Deck;

//struct PokerHand to hold 5 cards
typedef struct {
    Card pokerHand[5];
} PokerHand;


void createDeck(Deck *newDeck);
//Function to create a deck of cards and set their suits and ranks
void shuffleDeck(Deck *shuffleDeck);
//Function to shuffle the deck of cards
void dealPokerHand(Deck const *deck, PokerHand *hand, int card);
//Function to deal 5 cards into a poker hand
int checkPokerHandOfAKind(PokerHand *hand);
//Function to check if a poker hand has any pairs
int checkPokerHandFlush(PokerHand *hand);
//Function to check if a poker hand has a flush
void sortPokerHandRank(PokerHand *hand);
//Function to sort a poker hand in order of rank
int checkPokerHandTwoKind(PokerHand *hand);
//Function to check if a poker hand has two pairs
int checkPokerHandStraight(PokerHand *hand);
//Function to check if a poker hand contains a straight
char * getEnumName(char *enumName, int enumNumber, char enumType);
//Function to return the enum name rather than int

/*
 * function main. Program begins execution here.
 * @return EXIT_SUCCESS
 */
int main()
{

    //Declare Deck variable
    Deck *newDeck = NULL;

    //Declare PokerHand variable
    PokerHand *newPokerHand = NULL;

    //Declare int variable
    int cardsDelt = 0;
    int isPokerHandOfKind = 0;
    int isTwoKind = 0;
    int isFlush = 0;
    int isStraight = 0;

    //Declare char* variable
    char *enumName;

    //Set srand
    srand(time(NULL));

    //Dynamically allocate newDeck and newPokerHand and enumName;
    newDeck = malloc(sizeof(newDeck) * 52);
    newPokerHand = malloc(sizeof(newPokerHand) * 5);
    enumName = malloc(sizeof(char) * 10);

    //Sets the cards of newDeck
    createDeck(newDeck);

    //Shuffles the cards of newDeck
    shuffleDeck(newDeck);

    //Deals poker hands
    for( int i = 0; i < 5; i++ ) {
        dealPokerHand(newDeck, &newPokerHand[i], cardsDelt);
        cardsDelt += 5;
    }

    //Sorts poker hand
    for( int i = 0; i < 5; i++ ) {
        sortPokerHandRank(&newPokerHand[i]);
    }


    //Prints Poker Hands with card names and Rank Results
    for( int i = 0; i < 5; i++ ) {
        isPokerHandOfKind = checkPokerHandOfAKind(&newPokerHand[i]);
        isTwoKind = checkPokerHandTwoKind(&newPokerHand[i]);
        isFlush = checkPokerHandFlush(&newPokerHand[i]);
        isStraight = checkPokerHandStraight(&newPokerHand[i]);

        printf("Hand %d:\n", i);
        for( int j = 0; j < 5; j++ ) {
            printf("\t%d) %s of %s", j, getEnumName(enumName, newPokerHand[i].pokerHand[j].rank, 'r'), getEnumName(enumName, newPokerHand[i].pokerHand[j].suit, 's'));
            putchar('\n');
        }

        puts("\nHand Ranking Result: \n");

        printf("Pair?");
        if( isPokerHandOfKind == 2 ) {
            printf("  true\n");
        } else {
            printf("   false\n");
        }
        printf("Two Pair?");
        if( isTwoKind == 1 ) {
            printf("   true\n");
        } else {
            printf("   false\n");
        }
        printf("Three of a kind?");
        if( isPokerHandOfKind == 3 ) {
            printf("   true\n");
        } else {
            printf("   false\n");
        }
        printf("Four of a kind?\t");
        if( isPokerHandOfKind == 4 ) {
            printf("   true\n");
        } else {
            printf("   false\n");
        }
        printf("Flush?\t");
        if( isFlush == 1 ) {
            printf("   true\n");
        } else {
            printf("   false\n");
        }
        printf("Straight?\t");
        if( isStraight == 1 ) {
            printf("   true\n");
        } else {
            printf("   false\n");
        }
    }

    //Frees newDeck and newPokerHand
    free(newDeck);
    free(newPokerHand);
    free(enumName);

    //Sets newDeck and newPokerHand to NULL
    newDeck = NULL;
    newPokerHand = NULL;
    enumName = NULL;

    //Ends program
    return (EXIT_SUCCESS);
}

/*
 * function createDeck
 * This function creates a deck with 52 cards and sets
 * their suit and rank
 */
void createDeck(Deck *newDeck)
{
    if(newDeck != NULL) {
        int i = 0;
        int j = 1;
        int k = 1;
        int l = 0;

        for( l = 0; l < 52; l++ ) {
            newDeck->deckCard[i].suit = j;
            newDeck->deckCard[i].rank = k;

            i++;
            j++;
            k++;
            if( j % SUIT_SIZE == 0 ) {
                j = 1;
            }
            if( k % RANK_SIZE == 0 ) {
                k = 1;
            }
        }
    } else {
        puts("Deck must first be initialized to create deck...");
    }

}

/*
 * function shuffleDeck
 * This function shuffles a deck of 52 cards
 */
void shuffleDeck(Deck *shuffleDeck)
{
    int prevSuit;
    int prevRank;
    int randNum = 0;

    if( shuffleDeck != NULL ) {
        for( int i = 0; i < 52; i++ ) {
            randNum = rand() % 52;

            prevSuit = shuffleDeck->deckCard[i].suit;
            prevRank = shuffleDeck->deckCard[i].rank;

            shuffleDeck->deckCard[i].suit = shuffleDeck->deckCard[randNum].suit;
            shuffleDeck->deckCard[i].rank = shuffleDeck->deckCard[randNum].rank;

            shuffleDeck->deckCard[randNum].suit = prevSuit;
            shuffleDeck->deckCard[randNum].rank = prevRank;
        }
    } else {
        puts("Deck must first be initialized to shuffle deck...");
    }
}

/*
 * function dealPokerHand
 * This function deals a poker hand of five cards
 */
void dealPokerHand(Deck const *deck, PokerHand *hand, int card)
{
    int cardNum = 0;

    cardNum += card;

    if( deck != NULL && hand != NULL ) {
        for(int i = 0; i < 5; i++) {
            hand->pokerHand[i].suit = deck->deckCard[cardNum + i].suit;
            hand->pokerHand[i].rank = deck->deckCard[cardNum + i].rank;
        }
    } else {
        puts("Deck and PokerHand must be initialized to deal Poker Hand...");
    }

}

/*
 * function sortPokerHand
 * This function sorts the poker hand by rank
 */
void sortPokerHandRank(PokerHand *hand)
{
    int tempSuit = 0;
    int tempRank = 0;

    if( hand != NULL ) {
        for( int i = 0; i < 4; i++ ) {
            for(int j = i + 1; j < 5; j++) {
                tempSuit = hand->pokerHand[i].suit;
                tempRank = hand->pokerHand[i].rank;
                if( hand->pokerHand[i].rank > hand->pokerHand[j].rank ) {
                    hand->pokerHand[i].suit = hand->pokerHand[j].suit;
                    hand->pokerHand[i].rank = hand->pokerHand[j].rank;
                    hand->pokerHand[j].suit = tempSuit;
                    hand->pokerHand[j].rank = tempRank;
                }
            }
        }
    } else {
        puts("PokerHand must be initialized to sort Poker Hand...");
    }

}

/*
 * function checkPokerHandOfAKind
 * This function checks if a poker hand has a pair, three of a kind,
 * or four of a kind
 * @return int 0-4 based on how many of the same rank exists
 */
int checkPokerHandOfAKind(PokerHand *hand)
{
    int rank[RANK_SIZE] = {0};
    int ranking = 0;

    if( hand != NULL ) {
        for(int i = 0; i < 5; i++) {
            rank[hand->pokerHand[i].rank]++;
        }

        for( int i = 0; i < RANK_SIZE; i++ ) {
            if( rank[hand->pokerHand[i].rank] > ranking ) {
                ranking++;
            }
        }
    } else {
        puts("PokerHand must be initialized to check hand of kind...");
    }

    return ranking;
}

/*
 * function checkPokerHandFLush
 * This function checks if a poker hand has a flush
 * @return int 0 if it does not or 1 if it does contain a flush
 */
int checkPokerHandFlush(PokerHand *hand)
{
    int isFlush = 0;
    int suit[SUIT_SIZE] = {0};

    if( hand != NULL ) {
        for(int i = 0; i < 5; i++) {
            suit[hand->pokerHand[i].suit]++;
        }

        for( int i = 0; i < SUIT_SIZE; i++ ) {
            if( suit[i] == 5 ) {
                isFlush = 1;
            }
        }
    } else {
        puts("PokerHand must be initialized to check flush...");
    }

    return isFlush;
}

/*
 * function checkPokerHandTwoKind
 * This function checks if a poker hand has two pairs
 * @return int 0 if it does not or 1 if it does contains two pairs
 */
int checkPokerHandTwoKind(PokerHand *hand)
{
    int twoOfKind = 0;

    if( hand != NULL ) {
        if( hand->pokerHand[0].rank == hand->pokerHand[1].rank && hand->pokerHand[2].rank == hand->pokerHand[3].rank ) {
            twoOfKind = 1;
        } else if( hand->pokerHand[0].rank == hand->pokerHand[1].rank && hand->pokerHand[3].rank == hand->pokerHand[4].rank ) {
            twoOfKind = 1;
        } else if( hand->pokerHand[1].rank == hand->pokerHand[2].rank && hand->pokerHand[3].rank == hand->pokerHand[4].rank ) {
            twoOfKind = 1;
        }
    } else {
        puts("PokerHand must be initialized to check two of kind...");
    }


    return twoOfKind;
}

/*
 * function checkPokerHandStraight
 * This function checks if a poker hand has a straight
 * @return int 0 if it does not or 1 if it does contain a straight
 */
int checkPokerHandStraight(PokerHand *hand)
{
    int isStraight = 0;
    int rank[5] = {0};
    int startValue = 0;

    if( hand!= NULL ) {
        for( int i = 0; i < 5; i++ ) {
            rank[i] = hand->pokerHand[i].rank;
        }

        startValue = rank[0];

        if( startValue++ == rank[1] && startValue++ == rank[2] && startValue++ == rank[3] && startValue++ == rank[4]) {
            isStraight = 1;
        }
    } else {
        puts("PokerHand must be initialized to check for straight...");
    }


    return isStraight;
}

/*
 * function getEnumName
 * This function gets the int of an enum and returns it's name
 * @return char* string of the enum name
 */
char * getEnumName(char *enumName, int enumNumber, char enumType)
{
    if( enumName != NULL ) {
        if( enumType == 's' ) {
            switch(enumNumber) {
            case 1:
                enumName = "CLUB";
                break;

            case 2:
                enumName = "DIAMOND";
                break;

            case 3:
                enumName = "HEART";
                break;

            case 4:
                enumName = "SPADE";
                break;

            default:
                enumName = "CLUB";
            }
        }

        if( enumType == 'r' ) {
            switch(enumNumber) {
            case 1:
                enumName = "ACE";
                break;

            case 2:
                enumName = "TWO";
                break;

            case 3:
                enumName = "THREE";
                break;

            case 4:
                enumName = "FOUR";
                break;

            case 5:
                enumName = "FIVE";
                break;

            case 6:
                enumName = "SIX";
                break;

            case 7:
                enumName = "SEVEN";
                break;

            case 8:
                enumName = "EIGHT";
                break;

            case 9:
                enumName = "NINE";
                break;

            case 10:
                enumName = "TEN";
                break;

            case 11:
                enumName = "JACK";
                break;

            case 12:
                enumName = "QUEEN";
                break;

            case 13:
                enumName = "KING";
                break;
            }

        }
    } else {
        puts("char* must be initialized to put enumName...");
    }

    return enumName;
}
