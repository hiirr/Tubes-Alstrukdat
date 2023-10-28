#include "ADT/DynamicList.h"
#include <stdio.h>

DynamicList l;

void fill() {
    print_dynamic_list(&l);
    insert_last_dynamic_list(&l, 1);
    print_dynamic_list(&l);
    insert_last_dynamic_list(&l, 2);
    print_dynamic_list(&l);
    insert_last_dynamic_list(&l, 3);
    print_dynamic_list(&l);
    insert_last_dynamic_list(&l, 4);
    print_dynamic_list(&l);
    insert_last_dynamic_list(&l, 5);
    print_dynamic_list(&l);
}

void test_remove_last() {
    int removed;
    remove_last_dynamic_list(&l, &removed);
    printf("removed = %d\n", removed);
    print_dynamic_list(&l);
    remove_last_dynamic_list(&l, &removed);
    printf("removed = %d\n", removed);
    print_dynamic_list(&l);
    remove_last_dynamic_list(&l, &removed);
    printf("removed = %d\n", removed);
    print_dynamic_list(&l);
    remove_last_dynamic_list(&l, &removed);
    printf("removed = %d\n", removed);
    print_dynamic_list(&l);
    remove_last_dynamic_list(&l, &removed);
    printf("removed = %d\n", removed);
    print_dynamic_list(&l);
}

void test_remove_by_value() {
    remove_by_value_dynamic_list(&l, 3);
    print_dynamic_list(&l);
    remove_by_value_dynamic_list(&l, 4);
    print_dynamic_list(&l);
    remove_by_value_dynamic_list(&l, 5);
    print_dynamic_list(&l);
    remove_by_value_dynamic_list(&l, 1);
    print_dynamic_list(&l);
    remove_by_value_dynamic_list(&l, 2);
    print_dynamic_list(&l);
}

int main() {
    create_dynamic_list(&l, 2);

    fill();

    test_remove_last();

    fill();

    test_remove_by_value();
}