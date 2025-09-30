//
// Created by sh_ub on 30.09.2025.
//

#include "App.h"

#include <stdio.h>

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
    char choice;
    arraylist *list2 = create_arraylist();
    printf("\n=== Система учета оценок ===\n");
    print_menu();
    do {
        printf("Выберите действие: ");
        scanf("%s", &choice);

        switch (choice) {
            case '0':
                print_menu();
                break;

            case '1':
                addStudent(list2, input_student());
                break;

            case '2':
                char name[100];
                char subject[100];
                printf("Введите имя: ");
                scanf("%99s", name);
                printf("Введите предмет: ");
                scanf("%99s", subject);
                deleteStudent(list2, name, subject);
                break;

            case '3':
                char sub[100];
                printf("Введите предмет: ");
                scanf("%99s", sub);
                findStudentsBySubject(list2, sub);
                break;

            case '4':
                printAllStudents(list2);
                break;

            case '5':
                printf("Выход из программы...\n");
                break;

            default:
                printf("Неверный выбор!\n");
                break;
        }
    } while (choice != 5);

}