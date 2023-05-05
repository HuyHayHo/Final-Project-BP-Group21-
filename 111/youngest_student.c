#include "youngest_student.h"
#include <stdio.h>
#include "define.h"

//Check in turn from year, month, day. If greater than will get the value.
struct student findYoungestStudent( struct student *students, int numOfStudents) {
    struct student youngestStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (youngestStudent.birthdate.ate < students[i].birthdate.ate) {
            youngestStudent = students[i];
            break;
        }
        if (youngestStudent.birthdate.thd < students[i].birthdate.thd) {
            youngestStudent = students[i];
            break;
        }
        if (youngestStudent.birthdate.bir < students[i].birthdate.bir) {
            youngestStudent = students[i];
            break;
        }
    }
    return youngestStudent;
}