//
// Created by sh_ub on 30.09.2025.
//

#ifndef student_H
#define student_H

typedef struct {
    //information about the student (name), subject and mark.
    char *name;
    char *subject;
    double mark;
}  student;

student* create_student(char *name, char *subject, double mark);
student* input_student();
#endif