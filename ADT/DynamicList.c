#include "DynamicList.h"

#include <stdio.h>
#include <stdlib.h>

void create_dynamic_list(DynamicList *l, int capacity) {
    l->list = (int*)malloc(capacity * sizeof(int));
    l->length = 0;
    l->capacity = capacity;
}

void insert_last_dynamic_list(DynamicList *l, int element) {
    if (l->length != l->capacity) {
        l->list[l->length] = element;
        ++(l->length);
    } else {
        l->list = (int*)realloc(l->list, (2 * l->capacity) * sizeof(int));
        l->list[l->length] = element;
        ++(l->length);
        l->capacity *= 2;
    }
}
void remove_last_dynamic_list(DynamicList *l, int *element) {
    if (l->length == 0) {
        element = 0;
        return;
    }
    --(l->length);
    *element = l->list[l->length];
}

void print_dynamic_list(DynamicList *l) {
    printf("[");
    for (int i = 0; i < l->length - 1; ++i) {
        printf("%d,", l->list[i]);
    }
    if (l->length != 0) printf("%d", l->list[l->length - 1]);
    printf("] length = %d, capacity = %d\n", l->length, l->capacity);
}