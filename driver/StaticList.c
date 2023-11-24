#include "../ADT/StaticList.h"
#include <stdio.h>
#include <assert.h>

int main() {
    StaticList myList;

    create_static_list(&myList);
    assert(is_static_list_empty(myList));

    insert_first_static_list(&myList, 10);
    assert(!is_static_list_empty(myList));
    assert(static_list_length(myList) == 1);
    assert(elmt_static_list(myList, 0) == 10);

    insert_at_static_list(&myList, 20, 1);
    assert(static_list_length(myList) == 2);
    assert(elmt_static_list(myList, 1) == 20);

    insert_last_static_list(&myList, 30);
    assert(static_list_length(myList) == 3);
    assert(elmt_static_list(myList, 2) == 30);

    int val;
    delete_first_static_list(&myList, &val);
    assert(val == 10);
    assert(static_list_length(myList) == 2);

    delete_at_static_list(&myList, &val, 1);
    assert(val == 30);
    assert(static_list_length(myList) == 1);

    delete_last_static_list(&myList, &val);
    assert(val == 20);
    assert(static_list_length(myList) == 0);
    assert(is_static_list_empty(myList));

    printf("All tests passed successfully.\n");

    return 0;
}
