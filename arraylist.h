//
// Created by sh_ub on 30.09.2025.
//

#ifndef collection_h
#define collection_h
#include "student.h"

typedef struct {
    int length;
    int capacity;
    student **data;
} arraylist;

void deleteStudent(arraylist *list, char *name, char *subject);
int findStudent(arraylist *list, char *name, char *subject);
void addStudent(arraylist *list, student *new_student);
arraylist* create_arraylist();
void printAllStudents(arraylist *list);
void findStudentsBySubject(arraylist *list, char *subject);

#endif