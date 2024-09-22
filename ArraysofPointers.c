/*
Name: Victor Tran
Date: 9/26/22
Course: CIS 2107
HW#: Lab 05: ““Arrays of Pointers to Functions”

Objective: To design and implement array of function pointer.

The purpose of this program is to modify existing code related to examslecting
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average.

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/
#include <stdio.h>
#include <stdlib.h>

//Function prototypes.
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main() {
    //Gets user input for the amount of students, exams, and every exam grade for each student to be put into the 2d array that was initialized.
    printf("Enter number of students: ");
    int students;
    scanf("%d", &students);

    printf("Enter number of exams: ");
    int exams;
    scanf("%d", &exams);

    int grades[students][exams];

    for(size_t i = 0; i < students; i++) {
        for(size_t j = 0; j < exams; j++) {
            printf("Enter student %d's grade for exam %d: ", i, j);
            int userInput;
            scanf("%d", &userInput);
            grades[i][j] = userInput;
        }
    }

    //Initialization of the array of pointers to functions.
    void (*processGrades[4])(int students, int exams, int grades[students][exams]) = {printArray, minimum, maximum, average};

    //Prints out all the possible choices the user can tell the program to do.
    printf("\nEnter a choice:");
    printf("\n\t0  Print the array of grade");
    printf("\n\t1  Find the minimum grade");
    printf("\n\t2  Find the maximum grade");
    printf("\n\t3  Print the average on all tests for each student");
    printf("\n\t4  End program\n\n");

    //Asks the user for input to tell the program what to do until they enter 4 to end the program.
    size_t userInput;
    scanf("%u", &userInput);
    //Throws error message if user's input is less than 0 or greater than 4 and asks the user for another input.
    while(userInput < 0 || userInput > 4) {
            printf("\nError: the input you entered was invalid.\n");
            printf("Enter another choice:");
            printf("\n\t0  Print the array of grade");
            printf("\n\t1  Find the minimum grade");
            printf("\n\t2  Find the maximum grade");
            printf("\n\t3  Print the average on all tests for each student");
            printf("\n\t4  End program\n\n");
            scanf("%u", &userInput);
    }

    while(userInput >= 0 && userInput < 4) {
        (*processGrades[userInput])(students, exams, grades);
        printf("Enter another choice:");
        printf("\n\t0  Print the array of grade");
        printf("\n\t1  Find the minimum grade");
        printf("\n\t2  Find the maximum grade");
        printf("\n\t3  Print the average on all tests for each student");
        printf("\n\t4  End program\n\n");
        scanf("%u", &userInput);

        //Throws error message if user's input is less than 0 or greater than 4 and asks the user for another input.
        while(userInput < 0 || userInput > 4) {
            printf("\nError: the input you entered was invalid.\n");
            printf("Enter another choice:");
            printf("\n\t0  Print the array of grade");
            printf("\n\t1  Find the minimum grade");
            printf("\n\t2  Find the maximum grade");
            printf("\n\t3  Print the average on all tests for each student");
            printf("\n\t4  End program\n\n");
            scanf("%u", &userInput);
        }
    }

    printf("Ending program...\n");
}

//Prints out the 2d array of exam grades of the students.
void printArray(int students, int exams, int grades[students][exams]){
    printf("          ");
    for(int  i = 0; i < exams; i++) {
        printf("[%d]  ", i);
    }

    for(size_t i = 0; i < students; i++) {
        printf("\ngrades[%u] ", i);
        for(size_t j = 0; j < exams; j++) {
            printf("%-5d", grades[i][j]);
        }
    }
    printf("\n\n");
}

//Finds the minimum value out of all the exam grades of the students.
void minimum(int students, int exams, int grades[students][exams]){
    int minimum = 100;
    for(size_t i = 0; i < students; i++) {
        for(size_t j = 0; j < exams; j++) {
            if(grades[i][j] < minimum){
                minimum = grades[i][j];
            }
        }
    }
    printf("Lowest grade: %d\n\n", minimum);
}

//Finds the maximum value out of all the exam grades of the students.
void maximum(int students, int exams, int grades[students][exams]){
    int maximum = 0;
    for(size_t i = 0; i < students; i++) {
        for(size_t j = 0; j < exams; j++) {
            if(grades[i][j] > maximum) {
                maximum = grades[i][j];
            }
        }
    }
    printf("Highest grade: %d\n\n", maximum);
}

//Finds the average of the exam grades for each student.
void average(int students, int exams, int grades[students][exams]){
    for(size_t i = 0; i < students; i++) {
        double total = 0;
        for(size_t j = 0; j < exams; j++) {
            total += grades[i][j];
        }
        double average = total / exams;
        printf("The average grade for student %d is %0.2lf\n", i, average);
    }
    printf("\n");
}
