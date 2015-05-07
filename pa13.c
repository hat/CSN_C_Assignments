/*
 * @file pa13.c
 * @author Tony Hendrick
 * @version 4-28-15
 *
 * Program to create a .dat file of 20 integers and then randomly generate
 * 500 numbers between 0 and 19 and add one to the integers in the .dat file
 * every time they come up and then display the results and a histogram of
 * the results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 20 //Number of integers in the .dat file

int getRandNum(int smallest, int largest); //Gets random number
void buildFile(FILE **file, int fileSize); //Builds .dat file
void printFile(FILE *file); //prints .dat file
void addAsterisk(int amount); //prints asterisk character

/*
 * main function
 * @return EXIT_SUCCESS upon completion
 */
int main(void)
{
    FILE *file; //the file to read and write to

    srand((unsigned int)time(NULL)); //seed for the getRandNum function

    //Calls the buildFile function
    buildFile(&file, NUM_ITEMS);

    //calls the printFile
    printFile(file);

    return EXIT_SUCCESS;
}
//end main

/*
 * getRandNum function
 * Generates a random number between the first parameter
 * and the second parameter.
 * @param smallest integer to hold the smallest number that can be generated
 * @param largest integer to hold the largest number that can be generated
 */
int getRandNum(int smallest, int largest)
{
    int rand_num = 0; //integer to store a random number

    //gets a random number bwtween smallest and largest
    rand_num = rand() % largest + smallest;

    //returns the random number that was generated
    return rand_num;
}

/*
 * buildFile function
 * Builds a .dat file that has 20 integers.
 * @param **file a pointer to a pointer of a file
 * @param fileSize the number of items in the file
 */
void buildFile(FILE **file, int fileSize)
{
    int randNum = 0; //integer to store number returned from getRandNum
    int dataRead = 0; //integer to store the data read from the file

    //opens/creates the file
    *file = fopen("pa13.dat", "w+b");

    //checks if the file was succesfully opened
    if( !file )
    {
        puts("Error opening file...");
    }
    else
    {
        //writes 20 integers from 0-19 to the file
        for( int i = 0; i < fileSize; i++ )
        {
            fwrite(&randNum, sizeof(int), 1, *file);
        }

        //adds one to the integer that comes up from getRandNum function on the file
        for( int i = 0; i < 500; i++ )
        {
            //sets the return value of getRandNum to randNum
            randNum = getRandNum(0, NUM_ITEMS);

            //seeks from the beginning of the file to randNum
            fseek(*file, (int)(sizeof(int)) * randNum, SEEK_SET);
            //reads the data from the current spot in the file
            fread(&dataRead, sizeof(int), 1, *file);

            //seeks from the beginning of the file back to the randNum
            fseek(*file, (int)(sizeof(int)) * randNum, SEEK_SET);
            //adds one to the current value in the file and sets it to randNum
            randNum = dataRead + 1;
            //writes the current value of randNum to the current spot in the file
            fwrite(&randNum, sizeof(int), 1, *file);
        }
    }

    return;
}//end buildFile

/*
 * printFile function
 * Prints the data from a .dat file to the console.
 * @param *file a pointer to a file
 */
void printFile(FILE *file)
{
    int data = 0; //integer to hold the value read from the file
    int location = 0; //integer for the spot in the file

    //resets the file back to the beginning
    rewind(file);

    //reads the data from the beginning of the file
    fread(&data, sizeof(int), 1, file);

    //prints out the title for the forthcoming data
    puts("Value \t Count \t\tHistogram");

    //loop to run until the file ends
    while(!feof(file))
    {
        //prints out the current integer and the number of times it was randomly selected
        printf("%2d %9d\t\t", location++, data);

        //calls the addAsterisk function
        addAsterisk(data);

        //puts a newline
        putchar('\n');

        //reads the next integer in the file
        fread(&data, sizeof(int), 1, file);
    }

    return;
}

/*
 * addAsterisk function
 * Prints an asterisk character
 */
void addAsterisk(int amount)
{
    //loop to run until amount is hit
    for( int i = 0; i < amount; i++ )
    {
        //prints asterisk character
        putchar('*');
    }

    return;
}
