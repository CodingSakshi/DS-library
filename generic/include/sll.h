#ifndef  __$_SLL_H
#define  __$_SLL_H 1234
#include <common.h>

typedef struct __$_sll_node
{
void *ptr;
struct __$_sll_node *next;
}SinglyLinkedListNode;

typedef struct __$_sll
{
struct __$_sll_node *start;
struct __$_sll_node *end;
int size;
}SinglyLinkedList;

typedef struct __$_sll_iterator
{
SinglyLinkedListNode *node;
}SinglyLinkedListIterator;

SinglyLinkedList* createSinglyLinkedList(bool *success);

void destroySinglyLinkedList();

int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList);

void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList, void *ptr, bool *success);

void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, void *ptr, bool *success);

void* removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, bool *success);

void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList);

void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList, 

SinglyLinkedList *sourceSinglyLinkedList, bool *success);

void* getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList, int index, bool *success);

//below fun. is for traversing through singly linked list
SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList, bool *success);

bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator);

void* getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator, bool *success);
#endif
