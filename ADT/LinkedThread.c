#include "LinkedThread.h"
#include "../assets/ThreadComponent.h"
#include <stdlib.h>

LinkedThreadComponentAddress new_node_linked_thread(ThreadComponent thread) {
    LinkedThreadComponentAddress node = malloc(sizeof(LinkedThreadComponent));
    node->thread = thread;
    node->next = NULL;
    return node;
}

void create_linked_thread(LinkedThread *l) {
    (*l) = NULL;
}

boolean is_empty_linked_thread(LinkedThread l) {
    return l == NULL;
}

int length_linked_thread(LinkedThread l) {
    int size = 0;
    LinkedThreadComponentAddress current = l;
    while (current != NULL) {
        ++size;
        current = current->next;
    }
    return size;
}

ThreadComponent get_element_linked_thread(LinkedThread l, int idx) {
    LinkedThreadComponentAddress current = l;
    for (int i = 0; i < idx; ++i) {
        current = current->next;
    }
    return current->thread;
}

// void set_element_linked_thread(LinkedThread *l, int idx, ThreadComponent val) {}

// int index_of_linked_thread(LinkedThread l, ThreadComponent val) {}

void insert_first_linked_thread(LinkedThread *l, ThreadComponent val) {
    LinkedThreadComponentAddress first = new_node_linked_thread(val);
    if (first == NULL) return;

    first->next = *l;
    *l = first;
}

void insert_last_linked_thread(LinkedThread *l, ThreadComponent val) {
    if (is_empty_linked_thread(*l)) {
        insert_first_linked_thread(l, val);
    } else {
        LinkedThreadComponentAddress last = new_node_linked_thread(val);
        if (last == 0) return;

        LinkedThreadComponentAddress current = *l;
        for (int i = 1; i < length_linked_thread(*l); ++i) {
            current = current->next;
        }
        current->next = last;
    }
}

void insert_at_linked_thread(LinkedThread *l, ThreadComponent val, int idx) {
    if (idx == 0) insert_first_linked_thread(l, val);
    else {
        LinkedThreadComponentAddress new_node = new_node_linked_thread(val);
        if (new_node == 0) return;

        LinkedThreadComponentAddress current = *l;
        for (int i = 0; i < idx-1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_first_linked_thread(LinkedThread *l) {
    LinkedThreadComponentAddress temp = *l;
    *l = (*l)->next;
    free(temp->thread.text);
    free(temp->thread.datetime);
    free(temp);
}

void delete_last_linked_thread(LinkedThread *l) {
    if (length_linked_thread(*l) == 1) {
        delete_first_linked_thread(l);
    } else {
        LinkedThreadComponentAddress current = *l;
        for (int i = 2; i < length_linked_thread(*l); ++i) {
            current = current->next;
        }

        free(current->next->thread.datetime);
        free(current->next->thread.text);
        free(current->next);
        current->next = NULL;
    }
}

void delete_at_linked_thread(LinkedThread *l, int idx) {
    if (idx == 0) delete_first_linked_thread(l);
    else if (idx == length_linked_thread(*l) - 1) delete_last_linked_thread(l);
    else {
        LinkedThreadComponentAddress current = *l;
        for (int i = 0; i < idx - 1; ++i) {
            current = current->next;
        }
        LinkedThreadComponentAddress temp = current->next;
        current->next = temp->next;
        free(temp->thread.datetime);
        free(temp->thread.text);
        free(temp);
    }
}