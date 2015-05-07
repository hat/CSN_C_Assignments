/* 
 * @file:   pa10.c
 * @author: Tony Hendrick
 * @version 4-7-15
 * 
 * Program to learn how to dynamically allocate an array and sort
 * an array by dereferenced pointer values.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* createDynamicArray(int arraySize);
size_t getSizeOfArray();
void setArraysEqual(int *arrayOne, int *arrayTwo, int arraySize);
int* sortArrayAscending(int *array, int arraySize);
int* sortArrayDescending(int *array, int arraySize);
void printArray(int *array, int arraySize);

/*
 * main function
 * @return EXIT_SUCCESS upon completion
 */
int main(int argc, char** argv) 
{
    //Declare size_t variable
    size_t arraySize; //Amount of integers in the array
    
    //Declare int pointer variables
    int *array; //Pointer to an int for an array
    int *sortArray; //Pointer to an int for an array
    
    //Gets the size of the array between 1 and 20
    arraySize = getSizeOfArray();
    
    //*array becomes a dynamic array
    array = createDynamicArray(arraySize);
    
    //*sortArray becomes a dynamic array
    sortArray = (int*) calloc(arraySize + 1, sizeof(int*));
    
    //Sets *sortArray's values equal to *array's values
    setArraysEqual(sortArray, array, arraySize);
    
    //Prints out *array's values
    printf("Original: ");
    printArray(array, arraySize);
    
    //Prints out *sortArray's values after passing to sortArrayAscending
    printf("\nAscending: ");
    sortArray = sortArrayAscending(sortArray, arraySize);
    printArray(sortArray, arraySize);
    
    //Prints  out *sortArray's values after passing to sortArrayDescending
    printf("\nDescending: ");
    sortArray = sortArrayDescending(sortArray, arraySize);
    printArray(sortArray, arraySize);
    
    //Prints out *array's values
    printf("\nOriginal: ");
    printArray(array, arraySize);
    putchar('\n');
    
    //Frees memory used by *array and *sortArray
    free(array);
    free(sortArray);

    //Exits program
    return (EXIT_SUCCESS);
}

/*
 * createDynamicArray function
 * Creates a dynamic array of the specified size according to
 * arraySize
 * @return int* array with random values between 1 and 99
 */
int* createDynamicArray(int arraySize)
{
    int *array;
    int r;
    
    array = (int*) calloc(arraySize + 1, sizeof(int*));
    
    srand(time(NULL));
    
    for( int i = 0; i < arraySize; i++ )
    {
        r = rand() % 100;
        array[i] = r;
    }
    
    return array;
}

/*
 * getSizeOfArray function
 * gets the size of an array between 1 and 20
 * @return size_t size of array between 1 - 20
 */
size_t getSizeOfArray()
{
    size_t arraySize;
    
    do
    {
    printf("Enter array size (1 - 20): ");
    scanf("%lu", &arraySize);
    }while( arraySize < 1 || arraySize > 20 );
    
    return arraySize;
}

/*
 * setArraysEqual function
 * sets arrayOne's values equal to arrayTwo's values
 * @return void
 */
void setArraysEqual(int *arrayOne, int *arrayTwo, int arraySize)
{
    int i;
    
    for( i = 0; i < arraySize;  i++)
    {
        *(arrayOne + i) = *(arrayTwo + i);
    }
}

/*
 * sortArrayAscending function
 * sorts the array into ascending order
 * @return int* array sorted in ascending order
 */
int* sortArrayAscending(int *array, int arraySize)
{
    int *newArray;
    int temp;
    int i;
    int j;
    
    newArray = array;
    
    for( i = 0; i < arraySize; i++ )
    {
        for( j = i + 1; j < arraySize; j++ )
        {
            if( *(newArray+j) < *(newArray + i) )
            {
                temp = *(newArray + j);
                *(newArray + j) = *(newArray + i);
                *(newArray + i) = temp;
            }
        }
    }
    
    return newArray;
}

/*
 * sortArrayDescending function
 * sorts the array into descending order
 * @return int* array sorted in descending order
 */
int* sortArrayDescending(int *array, int arraySize)
{
    int* newArray;
    int temp;
    int i;
    int j;
    
    newArray = array;
    
    for( i = 0; i < arraySize; i++ )
    {
        for( j = 0; j < arraySize; j++ )
        {
            if( *(newArray + i) > *(newArray + j) )
            {
                temp = *(newArray + i);
                *(newArray + i) = *(newArray + j);
                *(newArray + j) = temp;
            }
        }
    }
    
    return newArray;
}

/*
 * printArray function
 * prints an array of size arraySize
 * @return void
 */
void printArray(int *array, int arraySize)
{
    for( int i = 0; i < arraySize; i++ )
    {
        printf("%d ", array[i]);
    }
}