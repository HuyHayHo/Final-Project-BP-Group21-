#include "oldest_student.h"
#include <stdio.h>
#include "define.h"

//Check in turn from year, month, day. If less than will get the value.
struct student findOldestStudent(struct student *students, int numOfStudents) {
    struct student oldestStudent = students[0];
    for (int i = 1; i < numOfStudents; i++) {
        if (oldestStudent.birthdate.ate > students[i].birthdate.ate) {
            oldestStudent = students[i];
            break;
        }
        if (oldestStudent.birthdate.thd > students[i].birthdate.thd) {
            oldestStudent = students[i];
            break;
        }
        if (oldestStudent.birthdate.bir > students[i].birthdate.bir) {
            oldestStudent = students[i];
            break;
        }
    }
    return oldestStudent;
}