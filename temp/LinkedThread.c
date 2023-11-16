#include "LinkedThread.h"
#include "../assets/ThreadComponent.h"

void create_linked_thread(LinkedThread *l) {}

boolean is_empty_linked_thread(LinkedThread l) {}

int length_linked_thread(LinkedThread l) {}

ThreadComponent get_element_linked_thread(LinkedThread l, int idx) {}

void set_element_linked_thread(LinkedThread *l, int idx, ThreadComponent val) {}

int index_of_linked_thread(LinkedThread l, ThreadComponent val) {}

void insert_first_linked_thread(LinkedThread *l, ThreadComponent val) {}

void insert_last_linked_thread(LinkedThread *l, ThreadComponent val) {}

void insert_at_linked_thread(LinkedThread *l, ThreadComponent val, int idx) {}

void delete_first_linked_thread(LinkedThread *l, ThreadComponent *val) {}

void delete_last_linked_thread(LinkedThread *l, ThreadComponent *val) {}

void delete_at_linked_thread(LinkedThread *l, int idx, ThreadComponent *val) {}