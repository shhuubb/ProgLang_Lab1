//
// Created by sh_ub on 30.09.2025.
//

#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    //information about the student (name), subject and mark.
    char *name;
    char *subject;
    double mark;
}  student;

student* create_student(const char *name, const char *subject, double mark);
student* input_student();
#endif