#include "../ADT/StaticList.h"
#include <stdio.h>

int main() {
    StaticList myList;

    create_static_list(&myList);
    if (is_static_list_empty(myList)) {
        printf("passed\n");
    }

    insert_first_static_list(&myList, 10);
    if (!is_static_list_empty(myList)) {
        printf("passed\n");
    }
    if (static_list_length(myList) == 1) {
        printf("passed\n");
    }
    if (elmt_static_list(myList, 0) == 10) {
        printf("passed\n");
    }

    insert_at_static_list(&myList, 20, 1);
    if (static_list_length(myList) == 2) {
        printf("passed\n");
    }
    if (elmt_static_list(myList, 1) == 20) {
        printf("passed\n");
    }

    insert_last_static_list(&myList, 30);
    if (static_list_length(myList) == 3) {
        printf("passed\n");
    }
    if (elmt_static_list(myList, 2) == 30) {
        printf("passed\n");
    }

    int val;
    delete_first_static_list(&myList, &val);
    if (val == 10) {
        printf("passed\n");
    }
    if (static_list_length(myList) == 2) {
        printf("passed\n");
    }

    delete_at_static_list(&myList, &val, 1);
    if (val == 30) {
        printf("passed\n");
    }
    if (static_list_length(myList) == 1) {
        printf("passed\n");
    }

    delete_last_static_list(&myList, &val);
    if (val == 20) {
        printf("passed\n");
    }
    if (static_list_length(myList) == 0) {
        printf("passed\n");
    }
    if (is_static_list_empty(myList)) {
        printf("passed\n");
    }

    printf("All tests passed successfully.\n");

    return 0;
}
