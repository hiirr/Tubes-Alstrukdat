#include "../ADT/DynamicList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    DynamicList myList;
    create_dynamic_list(&myList, 5);
    assert(myList.list != NULL && myList.length == 0 && myList.capacity == 5);

    for (int i = 0; i < 5; ++i) {
        insert_last_dynamic_list(&myList, i);
        assert(myList.length == i + 1);
    }
    assert(myList.capacity == 5);

    insert_last_dynamic_list(&myList, 5);
    assert(myList.capacity == 10);

    int removedElement;
    remove_last_dynamic_list(&myList, &removedElement);
    assert(removedElement == 5 && myList.length == 5);

    remove_by_value_dynamic_list(&myList, 2);
    assert(myList.length == 4);

    sort_descending_dynamic_list(&myList);
    for (int i = 0; i < myList.length - 1; ++i) {
        assert(myList.list[i] >= myList.list[i + 1]);
    }

    erase_all_dynamic_list(&myList);
    assert(myList.length == 0);

    deallocate_dynamic_list(&myList);

    printf("All tests passed successfully.\n");
    return 0;
}
