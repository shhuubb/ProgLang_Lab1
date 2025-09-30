//
// Created by sh_ub on 30.09.2025.
//
#include "domain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

student*  input_student() {
    char name[100];
    char subject[100];
    int mark;

    printf("Введите имя студента: ");
    scanf("%99s", name);
    printf("Введите предмет: ");
    scanf("%99s", subject);
    printf("Введите оценку от 0 до 5: ");
    scanf("%d", &mark);
    return create_student(name, subject, mark);
}

student* create_student(const char *name, const char *subject, double mark) {

    if (mark>5 || mark < 0) {
        fprintf(stderr, "Ошибка. Нужно Ввести оценку от 0 до 5.");
        return NULL;
    }



    student *s = (student*)malloc(sizeof(student));


    s->name = (char *)malloc(strlen(name) + 1);
    s->subject = (char *)malloc(strlen(subject) + 1);

    s->mark = mark;

    if (!s->name || !s->subject) {
        free(s->name); // Освобождаем, если одна из аллокаций не удалась
        free(s->subject);
        free(s);
        fprintf(stderr, "Ошибка: не удалось выделить память для строк\n");
        return NULL;
    }

    return s;
}
