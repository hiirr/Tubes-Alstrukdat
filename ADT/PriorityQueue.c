#include "PriorityQueue.h"

#include <stdio.h>
#include <stdlib.h>

void create_priority_queue(PriorityQueue *p, int capacity) {
    p->queue = (PriorityQueueElement*)malloc(capacity * sizeof(PriorityQueueElement));
    p->head = -1;
    p->tail = -1;
    p->capacity = capacity;
}

void enqueue(PriorityQueue *p, PriorityQueueElement element) {
    if (p->head == -1) { // && p->tail == -1
        p->head = 0;
        p->tail = 0;
        p->queue[0] = element;
    } else {

    }
}

void dequeue(PriorityQueue *p, PriorityQueueElement *element);

void print_priority_queue(PriorityQueue *p) {

}