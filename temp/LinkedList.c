#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedNodeAddress new_node_linked_list(int value) {
    LinkedNodeAddress new = malloc(sizeof(LinkedNode));
    new->value = value;
    new->next = 0;
    return new;
}

void create_linked_list(LinkedList *l) {
    (*l) = 0;
}

boolean is_empty_linked_list(LinkedList l) {
    return l == 0;
}

int length_linked_list(LinkedList l) {
    int size = 0;
    LinkedNodeAddress current = l;
    while (current != 0) {
        ++size;
        current = current->next;
    }

    return size;
}

int get_element_linked_list(LinkedList l, int idx) {
    LinkedNodeAddress current = l;
    for (int i = 0; i < idx; ++i) {
        current = current->next;
    }
    return current->value;
}

void set_element_linked_list(LinkedList *l, int idx, int val) {
    LinkedNodeAddress current = *l;
    for (int i = 0; i < idx; ++i) {
        current = current->next;
    }
    current->value = val;
}

int index_of_linked_list(LinkedList l, int val) {
    LinkedNodeAddress current = l;
    for (int i = 0; i < length_linked_list(l); ++i) {
        if (current->value == val) return i;
        current = current->next;
    }
    return -1;
}

void insert_first_linked_list(LinkedList *l, int val) {
    LinkedNodeAddress first = new_node_linked_list(val);
    if (first == 0) return;

    first->next = *l;
    *l = first;
}

void insert_last_linked_list(LinkedList *l, int val) {
    if (is_empty_linked_list(*l)) {
        insert_first_linked_list(l, val);
    } else {
        LinkedNodeAddress last = new_node_linked_list(val);
        if (last == 0) return;

        LinkedNodeAddress current = *l;
        for (int i = 1; i < length_linked_list(*l); ++i) {
            current = current->next;
        }
        current->next = last;
    }
}

void insert_at_linked_list(LinkedList *l, int val, int idx) {
    if (idx == 0) insert_first_linked_list(l, val);
    else {
        LinkedNodeAddress new_node = new_node_linked_list(val);
        if (new_node == 0) return;

        LinkedNodeAddress current = *l;
        for (int i = 0; i < idx-1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_first_linked_list(LinkedList *l, int *val) {
    *val = (*l)->value;
    LinkedNodeAddress temp = *l;
    *l = (*l)->next;
    free(temp);
}

void delete_last_linked_list(LinkedList *l, int *val) {
    if (length(*l) == 1) {
        delete_first_linked_list(l, val);
    } else {
        LinkedNodeAddress current = *l;
        for (int i = 2; i < length_linked_list(*l); ++i) {
            current = current->next;
        }

        *val = current->next->value;
        free(current->next);
        current->next = 0;
    }
}

void delete_at_linked_list(LinkedList *l, int idx, int *val) {
    if (idx == 0) delete_first_linked_list(l, val);
    else if (idx == length_linked_list(*l) - 1) delete_last_linked_list(l, val);
    else {
        LinkedNodeAddress current = *l;
        for (int i = 0; i < idx - 1; ++i) {
            current = current->next;
        }
        LinkedNodeAddress temp = current->next;
        *val = temp->value;
        current->next = temp->next;
        free(temp);
    }
}