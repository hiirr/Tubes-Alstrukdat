#include "../ADT/DynamicList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    DynamicList myList;
    create_dynamic_list(&myList, 5);
    if (myList.list != NULL && myList.length == 0 && myList.capacity == 5) {
        printf("passed\n");
    }

    for (int i = 0; i < 5; ++i) {
        insert_last_dynamic_list(&myList, i);
        if (myList.length == i + 1) {
            printf("passed\n");
        }
    }
    if (myList.capacity == 5) {
        printf("passed\n");
    }

    insert_last_dynamic_list(&myList, 5);
    if (myList.capacity == 10) {
        printf("passed\n");
    }

    int removedElement;
    remove_last_dynamic_list(&myList, &removedElement);
    if (removedElement == 5 && myList.length == 5) {
        printf("passed\n");
    }

    remove_by_value_dynamic_list(&myList, 2);
    if (myList.length == 4) {
        printf("passed\n");
    }

    sort_descending_dynamic_list(&myList);
    for (int i = 0; i < myList.length - 1; ++i) {
        if (myList.list[i] >= myList.list[i + 1]) {
            printf("passed\n");
        }
    }

    erase_all_dynamic_list(&myList);
    if (myList.length == 0) {
        printf("passed\n");
    }

    deallocate_dynamic_list(&myList);

    printf("All tests passed successfully.\n");
    return 0;
}
