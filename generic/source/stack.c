#ifndef __$_STACK_C
#define __$_STACK_C 12345

#include<stdlib.h>
#include<sll.h>
#include<stack.h>

Stack* createStack(bool *success)
{
Stack *stack;
SinglyLinkedList *singlyLinkedList;
singlyLinkedList = createSinglyLinkedList(success);
if(success == NULL) return NULL;
stack = (Stack*)malloc(sizeof(Stack));
if(stack == NULL) 
{
destroySinglyLinkedList(singlyLinkedList);
if(success) *success = False;
return NULL;
}
stack -> singlyLinkedList = singlyLinkedList;
if(success) *success = True;
return stack;
}

void pushOnStack(Stack *stack, void *ptr, bool *success)
{
if(success) *success = false;
if(stack == NULL || stack -> singlyLinkedList == NULL) return;
insertIntoSinglyLinkedList(stack -> singlyLinkedList, 0, ptr, success);
}

void* popFromStack(Stack *stack, bool *success)
{
void *ptr;
if(success) *success = false;
if(stack == NULL || stack -> singlyLinkedList == NULL) return NULL;
if(isStackEmpty(stack)) return NULL;
ptr = removeFromSinglyLinkedList(stack -> singlyLinkedList, 0, success);
// if(success) *success = true;
return ptr;
}

int getSizeOfStack(Stack *stack)
{
if(stack == NULL || stack -> singlyLinkedList == NULL) return -1;
return getSizeOfSinglyLinkedList(stack -> singlyLinkedList);
}

void *elementAtTopOfStack(Stack *stack, bool *success)
{
void *ptr;
if(success) *success = false;
if(stack == NULL || stack -> singlyLinkedList == NULL) return NULL;
if(isStackEmpty(stack)) return NULL;
ptr = getFromSinglyLinkedList(stack -> singlyLinkedList, 0, success);
if(success) *success = true;
return ptr;
}

bool isStackEmpty(Stack *stack)
{
if(stack == NULL || stack -> singlyLinkedList == NULL) return true;
if(getSizeOfSinglyLinkedList(stack -> singlyLinkedList) == 0) return true;
return false;
}

void clearStack(Stack *stack)
{
if(stack == NULL || stack -> singlyLinkedList == NULL) return;
clearSinglyLinkedList(stack -> singlyLinkedList);
}

void destroyStack(Stack *stack)
{
if(stack == NULL || stack -> singlyLinkedList == NULL) return;
destroySinglyLinkedList(stack -> singlyLinkedList);
free(stack);
}

#endif