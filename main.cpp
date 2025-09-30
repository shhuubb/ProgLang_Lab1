#include <memory>
#include <stdbool.h>
//25 7 array list
/*
 *
 *Gradebook is the book with information about students’ marks: it helps to the teacher (and student) answer two the
 *question about the marks by the subjects.
Technically, the book – is a set of records that combines information about the student (name), subject and mark.
Interaction between user and program organized by iterative displaying menu with available entries to do with the
gradebook and asking the user to select one of them. Menu has following entries:
add new item,
delete the item by student’s and subject name,
search by the subject (to display marks by this subject for all students).
*/
struct  {
    char *name;

} Student;

typedef int (*intFunc2)(void* a, void* b);

