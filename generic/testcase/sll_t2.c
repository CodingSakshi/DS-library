#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sll.h>  // Assuming your singly linked list library header is "sll.h"

typedef struct Contact {
    char name[50];
    char phoneNumber[20];
    char email[50];
} Contact;

void displayContact(Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Phone Number: %s\n", contact->phoneNumber);
    printf("Email: %s\n", contact->email);
    printf("----------\n");
}

void displayAllContacts(SinglyLinkedList *list) {
    SinglyLinkedListIterator iter = getSinglyLinkedListIterator(list, NULL);
    printf("Contact List:\n");
    while (hasNextInSinglyLinkedList(&iter)) {
        Contact *contact = (Contact*)getNextElementFromSinglyLinkedList(&iter, NULL);
        displayContact(contact);
    }
}

int main() {
    SinglyLinkedList *contactList;
    bool success;
    int choice;

    contactList = createSinglyLinkedList(&success);
    if (!success) {
        printf("Failed to create contact list.\n");
        return 1;
    }

    while (1) {
        printf("Contact Management System\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Contact *contact = (Contact*)malloc(sizeof(Contact));
                printf("Enter Name: ");
                scanf("%s", contact->name);
                printf("Enter Phone Number: ");
                scanf("%s", contact->phoneNumber);
                printf("Enter Email: ");
                scanf("%s", contact->email);
                addToSinglyLinkedList(contactList, (void*)contact, &success);
                if (success) {
                    printf("Contact added successfully.\n");
                } else {
                    printf("Failed to add contact.\n");
                }
                break;
            }

            case 2: {
                displayAllContacts(contactList);
                break;
            }

            case 3: {
                clearSinglyLinkedList(contactList);
                destroySinglyLinkedList(contactList);
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
