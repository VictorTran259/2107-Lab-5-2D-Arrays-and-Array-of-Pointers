/*
Victor Tran 9/20/22 CIS 2107
Lab 5 2D Arrays
Part 1 [75 points]: (2-Dimensional Array Functions)


1. [15 points] Write a function called max that returns the maximum value in the 2d array.

2. [15 points] Write a function called rowSum returns the sum of the elements in Row x of the 2d array.

3. [15 points] Write a function called columnSum returns the sum of the elements in Column x of the 2d array.

4. [15 points] Write a function called isSquare that checks if the array is square (i.e. every row has the same
       length as the 2d array itself).

5. [15 points] Write a function called displayOutputs that displays the 2 dim-array elements.


Part 2 [25 points]: (Testing main) Arrays2D

• First declare a 2-dim array. How to do that? You need to read the number of rows and the number of columns
from the user, and then it reads a corresponding entries to that size. E.g., if a user enters 3 for the number of rows,
and enters 3 for the number of columns, then we declare an array of 9 and then read 9 entries and store them in the
array. (Remember the Run-time Array Length!).

• Make calls to all functions in part 01 to match the sample demo below.

• Make sure you display the same exact messages.

• Use blank lines to separate outputs and make then more readable.
o Look how I printed out the output format below.


Sample run:

Let's create a 2Dim array!

 How many rows? 2
 How many columns? 3

 enter [0][0]: 11
 enter [0][1]: 22
 enter [0][2]: 33
 enter [1][0]: 44
 enter [1][1]: 55
 enter [1][2]: 66

Sum of row 1 = 66
Sum of row 2 = 165

Sum of column 1 = 55
Sum of column 2 = 77
Sum of column 3 = 99

This is not a square array.

Here is your 2Dim array:
[11, 22, 33]
[44, 55, 66]



Let's create a 2Dim array!

 How many rows? 3
 How many columns? 3

 enter [0][0]: 10
 enter [0][1]: 20
 enter [0][2]: 30
 enter [1][0]: 40
 enter [1][1]: 50
 enter [1][2]: 60
 enter [2][0]: 70
 enter [2][1]: 80
 enter [2][2]: 90

Sum of row 1 = 60
Sum of row 2 = 150
Sum of row 3 = 240

Sum of column 1 = 120
Sum of column 2 = 150
Sum of column 3 = 180

This is a square array.

Here is your 2Dim array:
[10, 20, 30]
[40, 50, 60]
[70, 80, 90]
*/

#include <stdio.h>

//Static declaration of int rows and columns.
static int rows;
static int columns;

//Function prototypes.
int max(int array[][columns]);
int rowSum(int rowInput, int array[][columns]);
int columnSum(int columnInput, int array[][columns]);
void isSquare();
void displayOutputs(int array[][columns]);

int main() {
    printf("Lets create a 2Dim array!\n\n");

    //Asks the user to specify their desired dimensions for the 2D array.
    printf("\tHow many rows? ");
    scanf("%d", &rows);

    printf("\tHow many columns? ");
    scanf("%d", &columns);

    //Declaration of 2D array of the dimensions specified by the user.
    int array[rows][columns];
    printf("\n");

    //Asks the user to enter integer inputs to fill in the 2D array.
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            printf("\tenter [%d][%d]: ", i, j);
            int userInput;
            scanf("%d", &userInput);
            array[i][j] = userInput;
        }
    }

    //The sample runs don't print out the max number so my code also doesn't print out the max number but I put a printf statement in comment here just in case.
    //Uncomment this printf statement below to get the compiler to print out the maximum number in the 2D array.
    //printf("\nMax = %d\n", max(array));

    //Finds the largest element within the 2D array.
    max(array);

    //Gets the sum of the elements in each row of the 2D array using the rowSum function.
    printf("\n");
    for(unsigned int i = 0; i < rows; i++) {
        printf("Sum of row %d = %d\n", i + 1, rowSum(i, array));
    }

    //Gets the sum of the elements in each column of the 2D array using the columnSum function.
    printf("\n");
    for(unsigned int i = 0; i < columns; i++) {
        printf("Sum of column %d = %d\n", i + 1, columnSum(i, array));
    }

    //Tests to see if the 2D array is a square. (length = witdth or rows = columns).
    isSquare();

    //Displays all the elements in the 2D array.
    displayOutputs(array);
}

//Returns the maximum value in the 2D array.
int max(int array[][columns]) {
    int maxNum = 0;
    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            if(array[i][j] > maxNum) {
                maxNum = array[i][j];
            }
        }
    }

    return maxNum;
}

//Returns the sum of the elements in Row x of the 2D array.
int rowSum(int rowInput, int array[][columns]) {
    int sumOfRowX = 0;
    for(size_t i = 0; i < columns; i++) {
        sumOfRowX += array[rowInput][i];
    }

    return sumOfRowX;
}

//Returns the sum of the elements in Column x of the 2D array.
int columnSum(int columnInput, int array[][columns]) {
    int sumOfColumnX = 0;
    for(size_t i = 0; i < rows; i++) {
        sumOfColumnX += array[i][columnInput];
    }

    return sumOfColumnX;
}

//Checks if the array is square (i.e. every row has the same length as the 2D array itself).
void isSquare() {
    if(rows == columns) {
        printf("\nThis is a square array.\n");
    }
    else{
        printf("\nThis is not a square array.\n");
    }
}

//Displays the 2 dim-array elements.
void displayOutputs(int array[][columns]) {
    printf("\nHere is your 2Dim array:\n");
    for(size_t i = 0; i < rows; i++) {
        printf("[");
        for(size_t j = 0; j < columns; j++) {
            if(j < columns - 1) {
                printf("%d, ", array[i][j]);
            }
            else {
                printf("%d", array[i][j]);
            }
        }
        printf("]\n");
    }
}
