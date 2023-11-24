#include <stdio.h>
#include "StaticList.h"

void create_static_list(StaticList *l) {
    for (int i = 0; i < CAPACITY; i++) {
        elmt_static_list(*l, i) = STATIC_LIST_MARK;
    }
}
int static_list_length(StaticList l) {
    int count = 0;
    
    for (int i = 0; i < CAPACITY; i++) {
        if (elmt_static_list(l,i) != STATIC_LIST_MARK) {
            count++;
        }
    }

    return count;
}

boolean is_static_list_empty(StaticList l) {
    return (static_list_length(l) == 0);
}
boolean is_static_list_full(StaticList l) {
    return (static_list_length(l) == CAPACITY);
}

void print_static_list(StaticList l) {
    printf ("[");
    if (!is_static_list_empty(l)) {
        for (int i = 0; i < static_list_length(l); i++) {
            printf ("%d", elmt_static_list(l,i));
            if (i != static_list_length(l)-1) {
                printf (",");
            }
        }
    }
    printf("]");
}

void insert_first_static_list(StaticList *l, int val) {
    for (int i = static_list_length(*l); i > 0; i--) {
        elmt_static_list(*l, i) = elmt_static_list(*l, (i-1));
    }

    elmt_static_list(*l, 0) = val;
}
void insert_at_static_list(StaticList *l, int val, int idx) {
    for (int i = static_list_length(*l); i > idx; i--) {
        elmt_static_list(*l, i) = elmt_static_list(*l, (i-1));
    }

    elmt_static_list(*l, idx) = val;
}
void insert_last_static_list(StaticList *l, int val) {
    elmt_static_list(*l, static_list_length(*l)) = val;
}

void delete_first_static_list(StaticList *l, int *val) {
    *val = elmt_static_list(*l, 0);

    for (int i = 0; i < static_list_length(*l)-1; i++) {
        elmt_static_list(*l, i) = elmt_static_list(*l, i+1);
    }

    elmt_static_list(*l, static_list_length(*l)-1) = STATIC_LIST_MARK;
}
void delete_at_static_list(StaticList *l, int *val, int idx) {
    *val = elmt_static_list(*l, idx);

    for (int i = idx; i < static_list_length(*l)-1; i++) {
        elmt_static_list(*l, i) = elmt_static_list(*l, i+1);
    }

    elmt_static_list(*l, static_list_length(*l)-1) = STATIC_LIST_MARK;
}
void delete_last_static_list(StaticList *l, int *val) {
    *val = elmt_static_list(*l, static_list_length(*l)-1);
    elmt_static_list(*l, static_list_length(*l)-1) = STATIC_LIST_MARK;
}