#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "boolean.h"

typedef struct LinkedNode *LinkedNodeAddress;
typedef LinkedNodeAddress LinkedList;

typedef struct LinkedNode {
    int value;
    LinkedNodeAddress next;
} LinkedNode;

LinkedNodeAddress new_node_linked_list(int value);

void create_linked_list(LinkedList *l);

boolean is_empty_linked_list(LinkedList l);

int length_linked_list(LinkedList l);

int get_element_linked_list(LinkedList l, int idx);

void set_element_linked_list(LinkedList *l, int idx, int val);

int index_of_linked_list(LinkedList l, int val);

void insert_first_linked_list(LinkedList *l, int val);

void insert_last_linked_list(LinkedList *l, int val);

void insert_at_linked_list(LinkedList *l, int val, int idx);

void delete_first_linked_list(LinkedList *l, int *val);

void delete_last_linked_list(LinkedList *l, int *val);

void delete_at_linked_list(LinkedList *l, int idx, int *val);

#endif