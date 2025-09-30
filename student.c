//
// Created by sh_ub on 30.09.2025.
//
#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

student*  input_student() {
    char name[100];
    char subject[100];
    float mark;

    printf("Введите имя студента: ");
    scanf("%99s", name);
    printf("Введите предмет: ");
    scanf("%99s", subject);
    printf("Введите оценку от 0 до 5: ");
    scanf("%f", &mark);
    return create_student(name, subject, mark);
}

student* create_student(char *name,char *subject, double mark) {
    if (mark>5 || mark < 0) {
        printf("Ошибка. Нужно Ввести оценку от 0 до 5.\n");
        return NULL;
    }

    student *s = malloc(sizeof(student));
    s->name = strdup(name);
    s->subject = strdup(subject);
    s->mark = mark;
    return s;
}
