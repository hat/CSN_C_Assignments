/*
 * @file:   pa11.c
 * @author: Tony Hendrick
 *
 * Program to search a string for a word and then replace that word with another
 * with all data being user entered.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 81 //Size of fullString malloc
#define SUB_REP_SIZE 11 //Size of subString and replaceString malloc

void get_data(char *fullString, char *subString, char *replaceString);
//Gets string of 80 or fewer characters
//Gets substring of 10 or fewer to search for
//Gets replacestring of 10 or fewer to replace substring with
char* replace_all(char *fullString, char *subString, char *replaceString);
//Creates a new string by replacing all occurences of the substring with replacestring
//If no occurences are found return old string
//Theoretically could grow to 800 chars long so use realloc
//Start with 80 char long and extend as needed
char* replace_same_length(char *fullString, char *subString, char *replaceString);
//Same as replace_all but only if subString and replaceString are same length
char* replace_sub_smaller(char *fullString, char *subString, char *replaceString);
//Same as replace_all but only if subString is smaller than replaceString
char* replace_sub_larger(char *fullString, char *subString, char *replaceString);
//Same as replace_all but only if subString is larger than replaceString
void print(char *string, int n);
//Prints the resulting string in n-length character lines
//If no space at n-length then puts hyphen and continues on next line
void removeNewLineChar(char *string);
//Removes newline character from a string

/*
 * function main. Program begins execution here.
 * @return EXIT_SUCCESS
 */
int main()
{
    //Declare char variables
    char *fullString = NULL;
    char *subString = NULL;
    char *replaceString = NULL;

    //Declare int variable
    int numCharPerLine = 0;

    //Dynamically allocate char pointers
    fullString = (char *) malloc(MAX_STRING_SIZE);
    subString = (char *) malloc(SUB_REP_SIZE);
    replaceString = (char *) malloc(SUB_REP_SIZE);

    //Call get_data function
    get_data(fullString, subString, replaceString);

    //Call replace_all function
    fullString = replace_all(fullString, subString, replaceString);

    //Get how many characters per line to print
    puts("Enter how many characters per line to print out: ");
    scanf("%i", &numCharPerLine);

    //Call print function
    print(fullString, numCharPerLine - 1);

    //Free memory
    free(fullString);
    free(subString);
    free(replaceString);

    //Exit program
    return (EXIT_SUCCESS);
}

////////////////////////////////////////////////////
///           FUNCTION DEFINITIONS               ///
////////////////////////////////////////////////////

/*
 * function get_data
 * @brief This function receives via stdin a string that is between
 * 1-80 characters long, a string that is between 1-10 characters
 * long, and another string that is within 1-10 characters long.
 * @param *fullString a string between 1-80 chars from stdin
 * @param *subString a string between 1-10 chars long used in searching fullString
 * @param *replaceString a string between 1-10 chars long used to replace subString
 */
void get_data(char *fullString, char *subString, char *replaceString)
{
    //Gets fullString from stdin
    puts("Enter a string (1-80 characters long): ");
    fgets(fullString, MAX_STRING_SIZE, stdin);

    //Removes newline character from fullString
    removeNewLineChar(fullString);

    //Gets subString from stdin
    puts("Enter the string to search for (1-10 characters long): ");
    fgets(subString, SUB_REP_SIZE, stdin);

    //Removes newline character from subString
    removeNewLineChar(subString);

    //Gets replaceString from stdin
    printf("Enter the string to replace \'%s\' with (1-10 characters long): ", subString);
    putchar('\n');
    fgets(replaceString, SUB_REP_SIZE, stdin);

    //Removes newline character from replaceString
    removeNewLineChar(replaceString);
}

/*
 * function removeNewLineChar
 * @brief This function removes the newline character from the string
 * that is passed in.
 * @param *string any string
 */
void removeNewLineChar(char *string)
{
    //Declare int variable
    unsigned long length;

    //Declare char variable
    char *toRemove;

    //Set length
    length = strlen(string) - 1;

    //Set toRemove
    toRemove = string + length;

    //Remove newline character
    string[length] =  string[length] == '\n' ? string[length] = '\0' : 0;
}

/*
 * function replace_all
 * @brief This function receives a string (fullString) that is between 1-80
 * characters long, a string (subString) that is between 1-10 characters long
 * and another string (replaceString) of the same size and checks to see
 * if subString is the same size, larger, or smaller than replaceString
 * and then calls on the appropriate function
 * @param *fullString a string between 1-80 chars
 * @param *subString a string between 1-10 chars long used in searching fullString
 * @param *replaceString a string between 1-10 chars long used to replace subString
 * @return The pointer to the new string after replacement
 */
char* replace_all(char *fullString, char *subString, char *replaceString)
{
    //Declare char variable
    char *newString = NULL;

    //If block to see if subString is the same length, larger, or smaller than replaceString
    if(strlen(subString) == strlen(replaceString)) {
        newString = (char *) malloc(MAX_STRING_SIZE);
        newString = replace_same_length(fullString, subString, replaceString);
    } else if(strlen(subString) > strlen(replaceString)) {
        newString = (char *) malloc(MAX_STRING_SIZE);
        newString = replace_sub_larger(fullString, subString, replaceString);
    } else if(strlen(subString) < strlen(replaceString)) {
        newString = (char *) malloc(MAX_STRING_SIZE);
        newString = replace_sub_smaller(fullString, subString, replaceString);
    }

    //Returns newString
    return newString;

    //Frees memory
    free(newString);
}

/*
 * function replace_same_length
 * @brief This function receives a string (fullString) that is between 1-80
 * characters long and then searches for a string (subString) that is between
 * 1-10 characters long and upon successfully finding that string (subString)
 * replaces it with another string (replaceString) that is within 1-10
 * characters long. subString and replaceString must be the same length.
 * @param *fullString a string between 1-80 chars
 * @param *subString a string between 1-10 chars long used in searching fullString
 * @param *replaceString a string between 1-10 chars long used to replace subString
 * @return The pointer to the new string after replacement
 */
char* replace_same_length(char *fullString, char *subString, char *replaceString)
{
    //Declares char variables
    char *newString = NULL;
    char *pointInFile = NULL;

    //Declares int variable
    unsigned long copyLength = 0;

    //Sets newString and pointInFile
    newString = (char *) malloc(MAX_STRING_SIZE); //The string to copy to

    //Do while loop runs until subString is not found
    do {
        //Sets pointInFile
        pointInFile = (strstr(fullString + strlen(newString), subString));

        //Checks if subString was found
        if(pointInFile != NULL) {
            //Sets copyLength
            copyLength = strlen(fullString) - strlen(pointInFile);

            //Copies fullString up to where subString was found to newString
            strncpy(newString + strlen(newString), fullString + strlen(newString), copyLength - strlen(newString));

            //Copies replaceString to newString
            strncpy(newString + strlen(newString), replaceString, strlen(replaceString));
        } else {
            //Copies whatever is left of fullString
            strncpy(newString + strlen(newString), fullString + strlen(newString), strlen(fullString));
        }
    } while(pointInFile != NULL);

    //returns newString
    return newString;

    //frees memory
    free(newString);
    free(pointInFile);
}

/*
 * function replace_sub_smaller
 * @brief This function receives a string (fullString) that is between 1-80
 * characters long and then searches for a string (subString) that is between
 * 1-10 characters long and upon successfully finding that string (subString)
 * replaces it with another string (replaceString) that is within 1-10
 * characters long. subString must be smaller than replaceString.
 * @param *fullString a string between 1-80 chars
 * @param *subString a string between 1-10 chars long used in searching fullString
 * @param *replaceString a string between 1-10 chars long used to replace subString
 * @return The pointer to the new string after replacement
 */
char* replace_sub_smaller(char *fullString, char *subString, char *replaceString)
{
    //Declare char variables
    char *newString = NULL;
    char *pointInFile = NULL;

    //Declare int variables
    unsigned long copyLength = 0;
    unsigned long differenceSubReplace = 0; //Difference between size of subString and replaceString
    unsigned long totalChange = 0; //Total number of letters added because of differenceSubReplace

    //Sets differenceSubReplace
    differenceSubReplace = strlen(subString) - strlen(replaceString);

    //Sets newString and pointInFile
    newString = (char *) malloc(MAX_STRING_SIZE);

    //Do while runs until subString is not found
    do {
        //Sets pointInFile
        pointInFile = (strstr(fullString + strlen(newString), subString));

        //Checks to see if adding replaceString will extend past newStrings size
        if( strlen(newString) + strlen(replaceString) > MAX_STRING_SIZE ) {
            //Reallocates correct amount of memory for newString and fullString
            newString = (char *) realloc(newString, MAX_STRING_SIZE + sizeof(char));
            fullString = (char *) realloc(newString, MAX_STRING_SIZE + sizeof(char));
        }

        //Checks to see if subString was found
        if(pointInFile != NULL) {
            //Sets copyLength
            copyLength = strlen(fullString) - strlen(pointInFile);

            //Copies fullString to newString up to where subString was found
            strncpy(newString + strlen(newString), fullString + strlen(newString) + totalChange, copyLength - strlen(newString) - totalChange);

            //Copies replaceString to newString
            strncpy(newString + strlen(newString), replaceString, strlen(replaceString));

            //Sets totalChange
            totalChange += differenceSubReplace;
        } else {
            //Copies the rest of the fullString to newString
            strncpy(newString + strlen(newString), fullString + strlen(newString) + totalChange, strlen(fullString) - totalChange);
        }
    } while(pointInFile != NULL);

    //Returns newString
    return newString;

    //Frees memory
    free(newString);
    free(pointInFile);
}

/*
 * function replace_sub_larger
 * @brief This function receives a string (fullString) that is between 1-80
 * characters long and then searches for a string (subString) that is between
 * 1-10 characters long and upon successfully finding that string (subString)
 * replaces it with another string (replaceString) that is within 1-10
 * characters long. subString must be larger than replaceString.
 * @param *fullString a string between 1-80 chars
 * @param *subString a string between 1-10 chars long used in searching fullString
 * @param *replaceString a string between 1-10 chars long used to replace subString
 * @return The pointer to the new string after replacement
 */
char* replace_sub_larger(char *fullString, char *subString, char *replaceString)
{
    //Declare char variables
    char *newString = NULL;
    char *pointInFile = NULL;

    //Declare int variables
    unsigned long copyLength = 0;
    unsigned long differenceSubReplace = 0; //Difference between subString and replaceString
    unsigned long count = 0; //Checks to make sure subString was found at least once

    //Set differenceSubReplace
    differenceSubReplace = strlen(subString) - strlen(replaceString);

    //Sets newString and pointInFile
    newString = (char *) malloc(MAX_STRING_SIZE);

    //Do while until subString is not found
    do {
        //Sets pointInFile
        pointInFile = (strstr(fullString + strlen(newString), subString));

        //Checks to see if subString was found
        if(pointInFile != NULL) {
            //Sets copyLength
            copyLength = strlen(fullString) - strlen(pointInFile);

            //Copies fullString to newString up to where subString was found
            strncpy(newString + strlen(newString), fullString + strlen(newString), copyLength - strlen(newString));

            //Copies replaceString to newString
            strncpy(newString + strlen(newString), replaceString, strlen(replaceString));

            //Skips over letters from subString left over
            fullString = fullString + differenceSubReplace;

            //Adds one to count
            count++;
        } else {
            //Makes sure that subString was found at least once
            if(count != 0) {
                //Goes back since subString was not found
                fullString = fullString - differenceSubReplace;

                //Copies rest of fullString to newString
                strncpy(newString + strlen(newString), fullString + strlen(newString) + differenceSubReplace, strlen(fullString));
            } else {
                //Copies all of fullString
                strncpy(newString + strlen(newString), fullString + strlen(newString), strlen(fullString));
            }
        }
    } while(pointInFile != NULL);

    //Returns newString
    return newString;

    //Frees memory
    free(newString);
    free(pointInFile);
}

/*
 * function print
 * @brief This function receives a string (fullString) that is between 1-80
 * characters long and then searches for a string (subString) that is between
 * 1-10 characters long and upon successfully finding that string (subString)
 * replaces it with another string (replaceString) that is within 1-10
 * characters long. subString must be larger than replaceString.
 * @param *s a pointer to an array of chars
 * @param n an integer of how many characters per line to print
 */
void print(char *string, int n)
{
    //Declare char variable
    char currentChar = ' ';

    //Goes through all of the chars of string
    for(int i = 0; i < (int)strlen(string); i++) {
        //Sets currentChar
        currentChar = (string[i]);

        //Checks to see i modulo n is 0
        if( i % n == 0 && i != 0 ) {
            //If block to determine how to print before new line
            if(string[i-1] != ' ' && string[i+1] == ' ' && currentChar != ' ') {
                //Prints currentChar
                putchar(currentChar);
                //Puts new line
                putchar('\n');
            } else if(string[i-1] == ' ' && currentChar != ' ') {
                //Puts a space
                putchar(' ');
                //Puts a new line
                putchar('\n');
                //Prints currentChar
                putchar(currentChar);
            } else if(string[i+1] != ' ' && currentChar != ' ') {
                //Puts a hyphen
                putchar('-');
                //Puts a new line
                putchar('\n');
                //Puts currentChar
                putchar(currentChar);
            } else if(currentChar == ' ') {
                //Puts currentChar
                putchar(currentChar);
                //Puts new line
                putchar('\n');
            }
        } else {
            putchar(currentChar);
        }
    }
}
