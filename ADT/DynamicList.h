#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "../boolean.h"

typedef struct DynamicList {
    int *list;
    int length;
    int capacity;
} DynamicList;

void create_dynamic_list(DynamicList *l, int capacity);

void insert_last_dynamic_list(DynamicList *l, int element);
void remove_last_dynamic_list(DynamicList *l, int *element);

void print_dynamic_list(DynamicList *l);

#endif