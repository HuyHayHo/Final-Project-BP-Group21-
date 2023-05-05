#ifndef F_FUNCTION_H
#define F_FUNCTION_H

struct student *students(int numOfStudents);
struct student findHighestBP(struct student *students, int numOfStudents);
struct student findHighestGPA(struct student *students, int numOfStudents);
struct student findLowestGPA(struct student *students, int numOfStudents);
void show_list(struct student *students, int numOfStudents);
void print_list(struct student *students, int numOfStudents);

#endif
