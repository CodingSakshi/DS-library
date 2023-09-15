#include <stdio.h>
#include <stdlib.h>
#include <stack.h>

// Define a simple structure to store data
typedef struct TestData {
    int value;
} TestData;

int main() {
    bool success;
    Stack *stack = createStack(&success);

    if (!success) {
        printf("Failed to create a stack.\n");
        return 1;
    }

    int choice;
    while (1) {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Get Size\n");
        printf("4. Get Top Element\n");
        printf("5. Is Empty?\n");
        printf("6. Clear Stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                TestData *data = (TestData*)malloc(sizeof(TestData));
                printf("Enter value to push onto the stack: ");
                scanf("%d", &(data->value));
                pushOnStack(stack, data, &success);
                if (success) {
                    printf("Pushed %d onto the stack.\n", data->value);
                } else {
                    printf("Failed to push onto the stack.\n");
                }
                break;
            }

            case 2: {
                TestData *poppedElement = (TestData*)popFromStack(stack, &success);
                if (success) {
                    printf("Popped: %d\n", poppedElement->value);
                    free(poppedElement);
                } else {
                    printf("Failed to pop from the stack.\n");
                }
                break;
            }

            case 3: {
                int size = getSizeOfStack(stack);
                printf("Stack size: %d\n", size);
                break;
            }

            case 4: {
                TestData *topElement = (TestData*)elementAtTopOfStack(stack, &success);
                if (success) {
                    printf("Element at the top of the stack: %d\n", topElement->value);
                } else {
                    printf("Failed to retrieve the element at the top of the stack.\n");
                }
                break;
            }

            case 5: {
                bool isEmpty = isStackEmpty(stack);
                if (isEmpty) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            }

            case 6: {
                clearStack(stack);
                printf("Stack cleared.\n");
                break;
            }

            case 7: {
                clearStack(stack);
                destroyStack(stack);
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
