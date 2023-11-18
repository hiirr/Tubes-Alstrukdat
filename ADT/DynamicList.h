#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "boolean.h"

typedef struct DynamicList {
    int *list;
    int length;
    int capacity;
} DynamicList;

void create_dynamic_list(DynamicList *l, int capacity);

void insert_last_dynamic_list(DynamicList *l, int element);
void remove_last_dynamic_list(DynamicList *l, int *element);
void remove_by_value_dynamic_list(DynamicList *l, int element);

void erase_all_dynamic_list(DynamicList *l);

void deallocate_dynamic_list(DynamicList *l);

void print_dynamic_list(DynamicList *l);

void sort_descending_dynamic_list(DynamicList *l);

#endif