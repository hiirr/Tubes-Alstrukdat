#include <PriorityQueue.h>

int main() {
    PriorityQueueElement e1, e2, e3;
    e1.priority = 1;
    e1.value = 10;

    e1.priority = 2;
    e1.value = 30;

    e1.priority = 3;
    e1.value = 20;

    PriorityQueue p;

    print_priority_queue(&p);
}