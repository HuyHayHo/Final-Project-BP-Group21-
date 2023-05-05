#include "f_function.h"
#include <stdio.h>
#include "define.h"

//find student with HighestBP
struct student findHighestBP(struct student *students, int numOfStudents) {
    struct student highestBPStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (students[i].programmingGrade > highestBPStudent.programmingGrade) {
            highestBPStudent = students[i];
        }
    }
    return highestBPStudent;
};

//find student with HighestGPA
struct student findHighestGPA(struct student *students, int numOfStudents) {
    struct student highestGPAStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (students[i].gpa > highestGPAStudent.gpa) {
            highestGPAStudent = students[i];
        }
    }
    return highestGPAStudent;
};

//find student with LowestGPA
struct student findLowestGPA(struct student *students, int numOfStudents) {
    struct student lowestGPAStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (students[i].gpa < lowestGPAStudent.gpa) {
            lowestGPAStudent = students[i];
        }
    }
    return lowestGPAStudent;
};

// Function show student list
void show_list(struct student *students, int numOfStudents){
    printf("\n");
    printf("+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
    printf("|  Student ID |          Full Name         |    Birthdate    | Algebra | Calculus| Basic Programming |   GPA  |\n");
    printf("+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");

    for (int i = 0; i < numOfStudents; i++) {

        printf("| %5s    | %s %s|    %d/%d/%d   | %6.2f  | %6.2f  |%12.2f       | %6.2f |\n",
            students[i].studentID,
            students[i].lastName,
            students[i].firstName,
            students[i].birthdate.bir,
            students[i].birthdate.thd,
            students[i].birthdate.ate,
            students[i].algebraGrade,
            students[i].calculusGrade,
            students[i].programmingGrade,
            students[i].gpa);
        printf("+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");    
    }
    
    printf("\n");
}

// Function print student list
void print_list(struct student *students, int numOfStudents){
    FILE *file = fopen("student_list.txt", "w");
    fprintf(file, "+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
    fprintf(file, "|  Student ID |          Full Name         |    Birthdate    | Algebra | Calculus| Basic Programming |   GPA  |\n");
    fprintf(file, "+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");

    for (int i = 0; i < numOfStudents; i++) {
        fprintf(file, "| %5s    | %s %s|    %d/%d/%d   | %6.2f  | %6.2f  |%12.2f       | %6.2f |\n",
            students[i].studentID,
            students[i].lastName, 
            students[i].firstName,
            students[i].birthdate.bir,
            students[i].birthdate.thd,
            students[i].birthdate.ate,
            students[i].algebraGrade,
            students[i].calculusGrade,
            students[i].programmingGrade,
            students[i].gpa);
        fprintf(file, "+-------------+----------------------------+-----------------+---------+---------+-------------------+--------+\n");
    }
    fclose(file);
}