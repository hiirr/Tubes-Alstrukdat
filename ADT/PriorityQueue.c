#include "PriorityQueue.h"

#include <stdio.h>
#include <stdlib.h>

void create_priority_queue(PriorityQueue *p) {
    p->head = -1;
    p->tail = -1;
}

int length_priority_queue(PriorityQueue *p) {
    if (p->head == -1) return 0;
    int end = p->head;
    if (end < p->tail) end += PRIORITY_QUEUE_CAPACITY;
    return end - p->tail + 1;
}

void enqueue(PriorityQueue *p, PriorityQueueElement element) {
    if (p->head == -1) { // && p->tail == -1
        p->head = 0;
        p->tail = 0;
        p->queue[0] = element;
    } else {
        int end = p->head;
        if (end < p-> tail) end += PRIORITY_QUEUE_CAPACITY;

        int left = p->tail;
        int right = end;

        // Binary search
        while (left < right) {
            int middle = left + (right - left) / 2;
            int actual_middle = middle % PRIORITY_QUEUE_CAPACITY;
            if (p->queue[actual_middle].priority >= element.priority) right = middle;
            else left = middle + 1;
        }
        int idx = left;

        if (element.priority > p->queue[idx].priority) {
            ++p->head;
            p->head %= PRIORITY_QUEUE_CAPACITY;
            p->queue[p->head] = element;
        } else {
            for (int i = end; i >= idx; --i) {
                int shifted_idx = (i + 1) % PRIORITY_QUEUE_CAPACITY;
                int actual_idx = i % PRIORITY_QUEUE_CAPACITY;
                p->queue[shifted_idx] = p->queue[actual_idx];
            }
            p->queue[idx] = element;
            ++p->head;
            p->head %= PRIORITY_QUEUE_CAPACITY;
        }
    }
}

void dequeue(PriorityQueue *p, PriorityQueueElement *element) {
    if (length_priority_queue(p) == 0) {
        element = 0;
        return;
    } else if (length_priority_queue(p) == 1) {
        *element = p->queue[p->head];
        p->head = -1;
        p->tail = -1;

    } else {
        *element = p->queue[p->head];
        --(p->head);
        p->head += PRIORITY_QUEUE_CAPACITY;
        p->head %= PRIORITY_QUEUE_CAPACITY;
    }
}

void print_priority_queue(PriorityQueue *p) {
    int end = p->head;
    if (end < p->tail) end += PRIORITY_QUEUE_CAPACITY;

    printf("[");
    for (int i = p->tail; i <= end-1; ++i) {
        int actual_idx = i % PRIORITY_QUEUE_CAPACITY;
        printf("%d,", p->queue[actual_idx].value);
    }
    if (length_priority_queue(p) != 0) printf("%d", p->queue[end].value);
    printf("], length = %d\n", length_priority_queue(p));
}