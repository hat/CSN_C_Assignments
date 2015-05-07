/*
 * @file pa14.c
 * @author Tony Hendrick
 * @version 5-05-15
 *
 * Program to manipulat numbers at a bit level.
 */

//preprocessor
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

//Define functions
void set_one(uint16_t *number, uint16_t pos);
void clear_one(uint16_t *number, uint16_t pos);
void flip(uint16_t *number, int pos);
uint32_t leftmost(uint32_t number);
uint32_t change_leftmost(uint32_t *number, uint32_t digit);
void printBinary(unsigned long num, int count, int binaryNum[]);
void printDecHexBin(unsigned long num);

/*
 * main function
 * @return EXIT_SUCCESS upon completion
 */
int main(void)
{
    uint16_t num1 = 54321; //number used to test set_one, clear_one,
                           //and flip
    uint32_t num2 = 2882400018; //number used to test leftmost and
                                //change_leftmost

    //prints out num1
    puts("Num1: ");
    printDecHexBin(num1);

    //calls set_one function on num1
    set_one(&num1, 3);

    //prints newline and then num1
    putchar('\n');
    puts("Test set_one");
    printDecHexBin(num1);

    //prints out num1
    puts("\nNum1: ");
    printDecHexBin(num1);

    //calls clear_one function on num1
    clear_one(&num1, 0);

    //prints newline and then num1
    putchar('\n');
    puts("Test clear_one");
    printDecHexBin(num1);

    //prints out num1
    puts("\nNum1: ");
    printDecHexBin(num1);

    //calls flip on num1
    flip(&num1, 0);

    //prints newline and then num1
    putchar('\n');
    puts("Tests flip");
    printDecHexBin(num1);

    //prints newline and then num2
    putchar('\n');
    puts("num2: ");
    printDecHexBin(num2);

    //prints newline and then the return value of
    //leftmost with num2 as the parameter
    putchar('\n');
    puts("Tests leftmost");
    printDecHexBin(leftmost(num2));

    //prints newline and then num2
    putchar('\n');
    puts("num2: ");
    printDecHexBin(num2);

    //prints newline and then the return value of
    //change_leftmost with num2 as the parameter
    putchar('\n');
    puts("Tests change_leftmost");
    printDecHexBin(change_leftmost(&num2, 0xF));

    //ends program
    return EXIT_SUCCESS;
}//end main

/*
 * set_one function
 * @brief Sets a specified bit to 1.
 * @param number reference to number
 * @param pos position to set to one
 */
void set_one(uint16_t *number, uint16_t pos)
{
    uint16_t mask; //mask used to toggle bit on

    //sets mask to the pos
    mask = 1 << pos;

    //toggles specified bit on
    *number |= mask;

    return;
}//end set_one

/*
 * clear_one function
 * @brief Sets a specified bit to 0.
 * @param number reference to number
 * @param pos position to set to one
 */
void clear_one(uint16_t *number, uint16_t pos)
{
    //toggles the bit off
    *number &= ~(1 << pos);

    return;
}//end clear_one

/*
 * flip function
 * @brief Flips all the bits values.
 * @param number reference to number
 * @param pos position to flip
 */
void flip(uint16_t *number, int pos)
{
    uint16_t mask = 1 << pos; //mask to toggle bit

    //toggles the first bit
    *number = *number ^ mask;

    //increments bit position
    pos++;

    //loop goes until all bits have been switched
    if( pos < (sizeof(uint16_t) * 8) )
    {
        //recalls flip to switch next bit
        flip(number, pos);
    }

    return;
}//end flip

/*
 * leftmost function
 * @brief gets the left most hex value
 * @param number the number to get the value from
 */
uint32_t leftmost(uint32_t number)
{
    return (number >> (sizeof(uint32_t) * 7));
}//end leftmost

/*
 * change_leftmost function
 * @brief changes the left most hex value
 * @param number the number to change
 * @param digit number to switch with the leftmost bit
 */
uint32_t change_leftmost(uint32_t *number, uint32_t digit)
{
    uint32_t temp = 0; //temp number

    //sets the leftmost bit to digit
    temp = temp << (sizeof(uint32_t) * 7) | digit;

    //sets the rest of temp to the remaining bits of number
    temp = temp << (sizeof(uint32_t) * 6) | *number >> (sizeof(uint32_t) * 1);

    //returns temp
    return (temp);
}//end change_leftmost

/*
 * printBinary function
 * @brief function to print a number in binary format
 * @param num the number to print
 * @param count the current number on
 * @parm binaryNum the array to save the binary digits
 */
void printBinary(unsigned long num, int count, int binaryNum[])
{
    //checks if num is divisible by 2 without a remainder
    if(num % 2 == 0)
    {
        //prints 0 if no remainder
        binaryNum[count] = 0;
    }
    else
    {
        //prints 1 if remainder
        binaryNum[count] = 1;
    }

    //divides number by 2 and increments count
    num = (num / 2);
    count++;

    //checks to see if number is less than 0
    if( num > 0 )
    {
        //recalls printBinary with current values
        printBinary(num, count, binaryNum);
    }
    else
    {
        //adds a zero if needed
        binaryNum[count] = 0;

        //prints out the number in binary format
        for(int i = count - 1; i >= 0; i--)
        {
            printf("%d", binaryNum[i]);
        }
    }
}//end printBinary

/*
 * printDecHexBin function
 * @brief function to print a number in decimal, hexadecimal,
 * and binary format
 * @param num number to print
 */
void printDecHexBin(unsigned long num)
{
    int binaryNum[100]; //holds the binary format digits

    //prints the number in decimal form
    printf("%15lu", num);

    //prints the number in hexadimal form
    printf("    %#10lX    ", num);

    //prints the number in binary form
    printBinary(num, 0, binaryNum);
}//end printDecHexBin
