//
// Created by sh_ub on 30.09.2025.
//
#include <stdlib.h>

#include "student.h"
#include "arraylist.h"

#include <stdio.h>
#include <string.h>

arraylist* create_arraylist() {
    arraylist *list3 = malloc(sizeof(arraylist));
    list3->capacity = 10;
    list3->data = malloc(10 * sizeof(student*));
    list3->length = 0;
    return list3;
}

 void arraylist_resize(arraylist *list) {
    int new_capacity = list->capacity * 2 ;
    student **new_data = realloc(list->data, sizeof(student*) * new_capacity);
    list->data = new_data;
    list->capacity = new_capacity;
}

void addStudent(arraylist *list, student *new_student) {
    printf("\n%d\n", list->capacity);
    if (list->length == list->capacity) {
        arraylist_resize(list);
    }
    list->data[list->length] = new_student;
    list->length++;
    printf("Студент %s добавлен в журнал\n", new_student->name);
}



int findStudent(arraylist *list, char *name, char *subject) {
    for (int i = 0; i < list->length; i++) {
        if (strcmp(list->data[i]->name, name) == 0 && strcmp(list->data[i]->subject, subject) == 0) {
            return i;
        }
    }
    return -1;
}

void deleteStudent(arraylist *list, char *name, char *subject) {
    int deletingIndex = findStudent(list, name, subject);
    if (deletingIndex == -1) {
        printf("Студента с именем %s и предметом %s не найдено\n", name, subject);
        return;
    }

    free(list->data[deletingIndex]->name); // Освободить строки
    free(list->data[deletingIndex]->subject);
    free(list->data[deletingIndex]); // Освободить student

    for (int j = deletingIndex; j < list->length - 1; j++) {
        list->data[j] = list->data[j + 1];
    }
    list->length--;
    list->data[list->length] = NULL;
    printf("Студент %s с предметом %s успешно удален\n", name, subject);
}

void printAllStudents(arraylist *list) {
    printf(" № |        Имя |    Предмет |   Оценка\n");
    for (int i = 1; i <= list->length; i++) {
        printf("%2d | %10s | %10s | %10f \n", i, list->data[i-1]->name, list->data[i-1]->subject, list->data[i-1]->mark);
    }
}
void findStudentsBySubject(arraylist *list, char *subject) {
    if (list->length == 0) {
        printf("Журнал пуст\n");
        return;
    }

    int found_count = 0;

    printf("Результаты поиска по предмету: %s\n", subject);

    for (int i = 0; i < list->length; i++) {
        student *s = list->data[i];
        if (s && strcmp(s->subject, subject) == 0) {
            found_count++;
            printf(" %2d. %-20s %-10.2f\n", found_count, s->name, s->mark);
        }
    }


    if (found_count == 0) {
        printf("Студентов по предмету '%s' не найдено\n", subject);
    } else {
        printf("Найдено студентов: %d\n", found_count);
    }
}