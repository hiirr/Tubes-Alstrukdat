#include "../ADT/LinkedThread.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// Helper function to create a ThreadComponent
ThreadComponent create_test_thread_component(int id, const char *text, const char *datetime) {
    ThreadComponent component;
    component.tweet_id = id;
    component.text = strdup(text);
    component.datetime = strdup(datetime);
    return component;
}

// Helper function to free a ThreadComponent
void free_thread_component(ThreadComponent *component) {
    free(component->text);
    free(component->datetime);
}

int main() {
    LinkedThread linkedThread;

    create_linked_thread(&linkedThread);
    assert(is_empty_linked_thread(linkedThread));

    ThreadComponent comp1 = create_test_thread_component(1, "Test Text 1", "2023-01-01");
    ThreadComponent comp2 = create_test_thread_component(2, "Test Text 2", "2023-01-02");

    insert_first_linked_thread(&linkedThread, comp1);
    assert(!is_empty_linked_thread(linkedThread));
    assert(length_linked_thread(linkedThread) == 1);

    insert_last_linked_thread(&linkedThread, comp2);
    assert(length_linked_thread(linkedThread) == 2);

    ThreadComponent firstElement = get_element_linked_thread(linkedThread, 0);
    assert(firstElement.tweet_id == 1);
    assert(strcmp(firstElement.text, "Test Text 1") == 0);

    ThreadComponent secondElement = get_element_linked_thread(linkedThread, 1);
    assert(secondElement.tweet_id == 2);
    assert(strcmp(secondElement.text, "Test Text 2") == 0);

    delete_first_linked_thread(&linkedThread);
    assert(length_linked_thread(linkedThread) == 1);

    delete_last_linked_thread(&linkedThread);
    assert(is_empty_linked_thread(linkedThread));

    free_thread_component(&comp1);
    free_thread_component(&comp2);

    printf("All tests passed successfully.\n");

    return 0;
}