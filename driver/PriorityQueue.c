#include "ADT/PriorityQueue.h"
#include <stdio.h>

int main() {
    PriorityQueueElement e1, e2, e3;
    e1.priority = 1;
    e1.value = 10;

    e2.priority = 2;
    e2.value = 30;

    e3.priority = 3;
    e3.value = 20;

    
    PriorityQueue p;
    create_priority_queue(&p);

    print_priority_queue(&p);
    enqueue(&p, e3);
    print_priority_queue(&p);
    enqueue(&p, e2);
    print_priority_queue(&p);
    enqueue(&p, e1);
    print_priority_queue(&p);

    PriorityQueueElement removed;
    dequeue(&p, &removed);
    printf("removed element with value %d and priority %d\n", removed.value, removed.priority);
    print_priority_queue(&p);
    dequeue(&p, &removed);
    printf("removed element with value %d and priority %d\n", removed.value, removed.priority);
    print_priority_queue(&p);
    dequeue(&p, &removed);
    printf("removed element with value %d and priority %d\n", removed.value, removed.priority);
    print_priority_queue(&p);

    enqueue(&p, e3);
    print_priority_queue(&p);
    enqueue(&p, e2);
    print_priority_queue(&p);
    enqueue(&p, e1);
    print_priority_queue(&p);
}