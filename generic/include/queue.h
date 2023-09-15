#ifndef __$_QUEUE_H
#define __$_QUEUE_H 123

#include<common.h>
#include<sll.h>

typedef struct __$_queue
{
SinglyLinkedList *singlyLinkedList;
}Queue;

Queue* createQueue(bool *success);
void addToQueue(Queue *queue, void *ptr, bool *success);
void *removeFromQueue(Queue *queue, bool *success);
int getSizeOfQueue(Queue *queue);
void* elementAtFrontOfQueue(Queue *queue, bool *success);
bool isQueueEmpty(Queue *queue);
void clearQueue(Queue *queue);
void destroyQueue(Queue *queue);
#endif