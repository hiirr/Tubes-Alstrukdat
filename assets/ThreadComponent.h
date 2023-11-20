#ifndef THREAD_COMPONENT_H
#define THREAD_COMPONENT_H

typedef struct ThreadComponent {
    int tweet_id;
    char *datetime;
    char *text;
} ThreadComponent;

// void print_utas(ThreadComponent *t, int spaces);

#endif