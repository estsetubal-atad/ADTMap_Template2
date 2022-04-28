#pragma once

typedef struct student {
    char name[200];
    char number[12];
    int grade;
} Student;

typedef struct student* PtStudent;

/**
 * @brief Creates and initializes a student
 * 
 * @param name [in] student name
 * @param number [in] student number
 * @param grade  [in] student grade
 * @return Student struct
 */
Student studentCreate(char *name, char *number, int grade);

/**
 * @brief Prints a student's details
 * 
 * @param s student to print
 */
void studentPrint(PtStudent s);