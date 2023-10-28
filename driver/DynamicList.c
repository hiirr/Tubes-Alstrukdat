#include "ADT/DynamicList.h"

int main() {
    DynamicList l;
    create_dynamic_list(&l, 2);
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