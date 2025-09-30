//
// Created by sh_ub on 30.09.2025.
//

#include "App.h"

#include <stdio.h>
#include <string.h>

#include "arraylist.h"

void print_menu() {
    printf("0. Показать доступные действия\n");
    printf("1. Добавить студента\n");
    printf("2. Удалить студента по имени и предмету\n");
    printf("3. Поиск по предмету\n");
    printf("4. Показать всех студентов\n");
    printf("5. Выход\n");
}

void start_program(){
    char choice[10];
    arraylist *list2 = create_arraylist();
    printf("\n=== Система учета оценок ===\n");
    print_menu();
    do {
        printf("Выберите действие: ");
        scanf("%9s", choice);

        if (strcmp(choice, "0") == 0) {
            print_menu();
        } else if (strcmp(choice, "1") == 0) {
            addStudent(list2, input_student());
        } else if (strcmp(choice, "2") == 0) {
            char name[100], subject[100];
            printf("Введите имя: ");
            scanf("%99s", name);
            printf("Введите предмет: ");
            scanf("%99s", subject);
            deleteStudent(list2, name, subject);
        } else if (strcmp(choice, "3") == 0) {
            char sub[100];
            printf("Введите предмет: ");
            scanf("%99s", sub);
            findStudentsBySubject(list2, sub);
        } else if (strcmp(choice, "4") == 0) {
            printAllStudents(list2);
        } else if (strcmp(choice, "5") == 0) {
            printf("Выход из программы...\n");
        } else {
            printf("Неверный выбор! Введите 0, 1, 2, 3, 4 или 5\n");
        }
    } while (strcmp(choice, "5") != 0);

}