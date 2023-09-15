#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sll.h>  

typedef struct Student {
    int roll;
    char name[20];
} Student;

void printStudent(Student *student) {
    printf("Roll no.: %d\n", student->roll);
    printf("Name: %s\n", student->name);
    printf("----------\n");
}

void displayAllStudents(SinglyLinkedList *list) {
    SinglyLinkedListIterator iter = getSinglyLinkedListIterator(list, NULL);
    printf("Student Records:\n");
    while (hasNextInSinglyLinkedList(&iter)) {
        Student *student = (Student*)getNextElementFromSinglyLinkedList(&iter, NULL);
        printStudent(student);
    }
}

int main() {
    SinglyLinkedList *studentList;
    bool success;
    int choice;

    studentList = createSinglyLinkedList(&success);
    if (!success) {
        printf("Failed to create student list.\n");
        return 1;
    }

    while (1) {
        printf("School Management System\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Student *student = (Student*)malloc(sizeof(Student));
                printf("Enter Roll No: ");
                scanf("%d", &student->roll);
                printf("Enter Name: ");
                scanf("%s", student->name);
                addToSinglyLinkedList(studentList, (void*)student, &success);
                if (success) {
                    printf("Student added successfully.\n");
                } else {
                    printf("Failed to add student.\n");
                }
                break;
            }

            case 2: {
                displayAllStudents(studentList);
                break;
            }

            case 3: {
                int rollToUpdate;
                printf("Enter Roll No to update: ");
                scanf("%d", &rollToUpdate);
                SinglyLinkedListIterator iter = getSinglyLinkedListIterator(studentList, NULL);
                while (hasNextInSinglyLinkedList(&iter)) {
                    Student *student = (Student*)getNextElementFromSinglyLinkedList(&iter, NULL);
                    if (student->roll == rollToUpdate) {
                        printf("Enter updated Name: ");
                        scanf("%s", student->name);
                        printf("Student updated successfully.\n");
                        break;
                    }
                }
                break;
            }

            case 4: {
    int rollToDelete;
    printf("Enter Roll No to delete: ");
    scanf("%d", &rollToDelete);

    SinglyLinkedListIterator iter = getSinglyLinkedListIterator(studentList, NULL);
    int index = 0;
    bool found = false;
    Student *deletedStudent = NULL;

    while (hasNextInSinglyLinkedList(&iter)) {
        Student *student = (Student*)getNextElementFromSinglyLinkedList(&iter, NULL);
        if (student->roll == rollToDelete) {
            deletedStudent = (Student*)removeFromSinglyLinkedList(studentList, index, &success);
            if (success) {
                printf("Student deleted successfully.\n");
                free(deletedStudent);  // Free the memory of the deleted student
            } else {
                printf("Failed to delete student.\n");
            }
            found = true;
            break;
        }
        index++;
    }

    if (!found) {
        printf("Student with Roll No %d not found.\n", rollToDelete);
    }

    break;
}


            case 5: {
                clearSinglyLinkedList(studentList);
                destroySinglyLinkedList(studentList);
                printf("Exiting...\n");
                return 0;
            }

            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}
