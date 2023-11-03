#ifndef THREAD_H
#define THREAD_H

typedef struct Thread {
    int idx;
    char *datetime;
    char *text;
} Thread;

void print_utas(Thread *t);

#endif