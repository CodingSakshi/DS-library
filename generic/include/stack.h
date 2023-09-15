#ifndef __$_STACK_H
#define __$_STACK_H

#include<common.h>
#include<sll.h>

typedef struct __$_stack
{
SinglyLinkedList *singlyLinkedList;
}Stack;

Stack* createStack(bool *success);
void pushOnStack(Stack *stack, void *ptr, bool *success);
void* popFromStack(Stack *stack, bool *success);
int getSizeOfStack(Stack *stack);
void* elementAtTopOfStack(Stack *stack, bool *success);
bool isStackEmpty(Stack *stack);
void clearStack(Stack *stack);
void destroyStack(Stack *stack);
#endif