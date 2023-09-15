#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

// Define a simple structure to store data
typedef struct TestData {
    int value;
} TestData;

int main() {
    bool success;
    Stack *queue = createStack(&success);

    if (!success) {
        printf("Failed to create a queue.\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("Queue Operations:\n");
        printf("1. Enqueue (Push)\n");
        printf("2. Dequeue (Pop)\n");
        printf("3. Get Size\n");
        printf("4. Get Front Element\n");
        printf("5. Is Empty?\n");
        printf("6. Clear Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                TestData *data = (TestData*)malloc(sizeof(TestData));
                printf("Enter value to enqueue: ");
                scanf("%d", &(data->value));
                pushOnStack(queue, data, &success);
                if (success) {
                    printf("Enqueued %d.\n", data->value);
                } else {
                    printf("Failed to enqueue.\n");
                }
                break;
            }

            case 2: {
                if (!isStackEmpty(queue)) {
                    Stack *tempStack = createStack(&success);
                    while (!isStackEmpty(queue)) {
                        TestData *dequeuedElement = (TestData*)popFromStack(queue, &success);
                        if (success) {
                            pushOnStack(tempStack, dequeuedElement, &success);
                        } else {
                            printf("Failed to dequeue from the queue.\n");
                        }
                    }
                    TestData *dequeuedElement = (TestData*)popFromStack(tempStack, &success);
                    if (success) {
                        printf("Dequeued: %d\n", dequeuedElement->value);
                        free(dequeuedElement);
                    } else {
                        printf("Failed to dequeue from the queue.\n");
                    }
                    while (!isStackEmpty(tempStack)) {
                        TestData *enqueuedElement = (TestData*)popFromStack(tempStack, &success);
                        if (success) {
                            pushOnStack(queue, enqueuedElement, &success);
                        } else {
                            printf("Failed to re-enqueue to the queue.\n");
                        }
                    }
                    destroyStack(tempStack);
                } else {
                    printf("Queue is empty. Cannot dequeue.\n");
                }
                break;
            }

            case 3: {
                int size = getSizeOfStack(queue);
                printf("Queue size: %d\n", size);
                break;
            }

            case 4: {
                if (!isStackEmpty(queue)) {
                    Stack *tempStack = createStack(&success);
                    TestData *frontElement = NULL;
                    while (!isStackEmpty(queue)) {
                        TestData *element = (TestData*)popFromStack(queue, &success);
                        if (success) {
                            frontElement = element;
                            pushOnStack(tempStack, element, &success);
                        } else {
                            printf("Failed to access the front element.\n");
                        }
                    }
                    while (!isStackEmpty(tempStack)) {
                        TestData *element = (TestData*)popFromStack(tempStack, &success);
                        if (success) {
                            pushOnStack(queue, element, &success);
                        } else {
                            printf("Failed to re-enqueue to the queue.\n");
                        }
                    }
                    destroyStack(tempStack);
                    if (frontElement != NULL) {
                        printf("Front element of the queue: %d\n", frontElement->value);
                    } else {
                        printf("Failed to access the front element.\n");
                    }
                } else {
                    printf("Queue is empty. No front element.\n");
                }
                break;
            }

            case 5: {
                bool isEmpty = isStackEmpty(queue);
                if (isEmpty) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            }

            case 6: {
                clearStack(queue);
                printf("Queue cleared.\n");
                break;
            }

            case 7: {
                clearStack(queue);
                destroyStack(queue);
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
