#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#define PRIORITY_QUEUE_CAPACITY 20

typedef struct PriorityQueueElement {
    int value;
    int priority;
} PriorityQueueElement;


typedef struct PriorityQueue {
    PriorityQueueElement queue[PRIORITY_QUEUE_CAPACITY];
    int head;
    int tail;
} PriorityQueue;

void create_priority_queue(PriorityQueue *p);

void enqueue(PriorityQueue *p, PriorityQueueElement element);

void dequeue(PriorityQueue *p, PriorityQueueElement *element);

void print_priority_queue(PriorityQueue *p);

#endif