#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct PriorityQueueElement {
    int value;
    int priority;
} PriorityQueueElement;


typedef struct PriorityQueue {
    PriorityQueueElement *queue;
    int head;
    int tail;
    int capacity;
} PriorityQueue;

void create_priority_queue(PriorityQueue *p);

void enqueue(PriorityQueue *p, PriorityQueueElement element);

void dequeue(PriorityQueue *p, PriorityQueueElement *element);

void print_priority_queue(PriorityQueue *p);

#endif