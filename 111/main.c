//Group 21 class A
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "oldest_student.h"
#include "youngest_student.h"
#include "f_function.h"
#include "define.h"

int main(){

    FILE *fp;
    char ch;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Cannot open to file");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    printf("\n");
    char c;
    printf("Press Enter to continue...");
    scanf("%c", &c);
    printf("Start the final project %c\n", c);
    
    int numOfStudents;
    do
    {
        printf("Enter number of students (maximum 1000): ");
        scanf ("%d", &numOfStudents);
    } while (numOfStudents > MAXIMUM_STUDENTS);


    //insert data
    struct student students[numOfStudents];
    for (int i = 0; i < numOfStudents; i++) {
        printf("Enter information for student %d:\n", i+1);
        printf("\nStudent ID: ");
        scanf(" %s", students[i].studentID);
        printf("\n");
        printf("Last Name: ");
        scanf(" %s", students[i].lastName);
        printf("\n");
        printf("First Name: ");
        scanf(" %s", students[i].firstName);
        printf("\n");
        printf("Birthdate (dd/mm/yyyy) \n"); 
        scanf("%d %d %d", &students[i].birthdate.bir, &students[i].birthdate.thd, &students[i].birthdate.ate);
        printf("\n");
        printf("Algebra grade: ");
        scanf("%f", &students[i].algebraGrade);
        printf("Calculus grade: ");
        scanf("%f", &students[i].calculusGrade);
        printf("Programming grade: ");
        scanf("%f", &students[i].programmingGrade);
        printf("\n");
        // calculate GPA
        students[i].gpa = (students[i].algebraGrade + students[i].calculusGrade + students[i].programmingGrade) / 3.0;
    }

    // show functions
    while (1)
    {
        printf("\nOption: \n1. Show list \n2. Print list\n3. Highest BP\n4. Highest GPA\n5. Lowest GPA\n6. Oldest student\n7. Youngest student\n");
        int opt = 0;
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            //Print student list as a table to screen
            show_list(students, numOfStudents);
            break;
        case 2:;
            //Print student list as a table to a text file
            print_list(students, numOfStudents);
            printf("\nSuccess!\n");
            break;
        case 3:;
            //Print the student with highest GPA
            struct student highestGPAStudent = findHighestGPA(students, numOfStudents);
            for (int i = 0; i < numOfStudents; i++) {
                if ( students[i].gpa == highestGPAStudent.gpa ) {
                    printf("Student with highest GPA:\n");  
                    printf("ID: %s\n", students[i].studentID);
                    printf("Name: %s %s\n", students[i].lastName, students[i].firstName);
                    printf("GPA: %.2f\n", students[i].gpa);
                    printf("\n");
                }
            }
            break;
        case 4:;
            //Print the student with lowest GPA
            struct student lowestGPAStudent = findLowestGPA(students, numOfStudents);
            for (int i = 0; i < numOfStudents; i++) {
                if ( students[i].gpa == lowestGPAStudent.gpa ) {    
                    printf("Student with lowest GPA:\n");
                    printf("ID: %s\n", students[i].studentID);
                    printf("Name: %s %s\n", students[i].lastName, students[i].firstName);
                    printf("GPA: %.2f\n", students[i].gpa);
                    printf("\n");
                }
            }
            break;
        case 5:;
            //Print the student with highest BP grade
            struct student highestBPStudent = findHighestBP(students, numOfStudents);
            for (int i = 0; i < numOfStudents; i++) {
                if ( students[i].programmingGrade == highestBPStudent.programmingGrade ){
                    printf("Student with highest BP grade:\n");
                    printf("ID: %s\n", students[i].studentID);
                    printf("Name: %s %s\n", students[i].lastName, students[i].firstName);
                    printf("Basic Programming grade: %.2f\n", students[i].programmingGrade);
                    printf("\n");
                }
            }
            break;
        case 6:;
            //Print the Oldest Student
            struct student oldestStudent = findOldestStudent(students, numOfStudents);
            for (int i = 0; i < numOfStudents; i++) {
                if ( students[i].birthdate.ate == oldestStudent.birthdate.ate 
                && students[i].birthdate.thd == oldestStudent.birthdate.thd 
                && students[i].birthdate.bir == oldestStudent.birthdate.bir){
                    printf("Oldest student:\n");
                    printf("ID: %s\n", students[i].studentID);
                    printf("Name: %s %s\n", students[i].lastName, students[i].firstName);
                    printf("Birthdate: %d %d %d\n", students[i].birthdate.bir, students[i].birthdate.thd, students[i].birthdate.ate);
                    printf("\n");}
            }
            break;
        case 7:;
            //Print the Youngest Student
            struct student youngestStudent = findYoungestStudent(students, numOfStudents);
            for (int i = 0; i < numOfStudents; i++) {
                if ( students[i].birthdate.ate == youngestStudent.birthdate.ate && students[i].birthdate.thd == youngestStudent.birthdate.thd && students[i].birthdate.bir == youngestStudent.birthdate.bir){
                    printf("Oldest student:\n");
                    printf("ID: %s\n", students[i].studentID);
                    printf("Name: %s %s\n", students[i].lastName, students[i].firstName);
                    printf("Birthdate: %d %d %d\n", students[i].birthdate.bir, students[i].birthdate.thd, students[i].birthdate.ate);
                    printf("\n");}
            }
            break;
        default:
            printf("Reselect!\n");
            break;
        }
    
    }

}

