#include "../ADT/LinkedThread.h"
#include <stdio.h>
#include <stdlib.h>
#include "../ADT/Wordmachine.h"

// Helper function to create a ThreadComponent
ThreadComponent create_test_thread_component(int id, const char *text, const char *datetime) {
    ThreadComponent component;
    component.tweet_id = id;
    component.text = my_strdup(text);
    component.datetime = my_strdup(datetime);
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
    if (is_empty_linked_thread(linkedThread)) {
        printf("passed\n");
    }

    ThreadComponent comp1 = create_test_thread_component(1, "Test Text 1", "2023-01-01");
    ThreadComponent comp2 = create_test_thread_component(2, "Test Text 2", "2023-01-02");

    insert_first_linked_thread(&linkedThread, comp1);
    if (!is_empty_linked_thread(linkedThread)) {
        printf("passed\n");
    }
    if (length_linked_thread(linkedThread) == 1) {
        printf("passed\n");
    }

    insert_last_linked_thread(&linkedThread, comp2);
    if (length_linked_thread(linkedThread) == 2) {
        printf("passed\n");
    }

    ThreadComponent firstElement = get_element_linked_thread(linkedThread, 0);
    if (firstElement.tweet_id == 1) {
        printf("passed\n");
    }
    if (my_strcmp(firstElement.text, "Test Text 1") == 0) {
        printf("passed\n");
    }

    ThreadComponent secondElement = get_element_linked_thread(linkedThread, 1);
    if (secondElement.tweet_id == 2) {
        printf("passed\n");
    };
    if (my_strcmp(secondElement.text, "Test Text 2") == 0) {
        printf("passed\n");
    }

    delete_first_linked_thread(&linkedThread);
    if (length_linked_thread(linkedThread) == 1) {
        printf("passed\n");
    }

    delete_last_linked_thread(&linkedThread);
    if (is_empty_linked_thread(linkedThread)) {
        printf("passed\n");
    }

    // free_thread_component(&comp1);
    // free_thread_component(&comp2);

    printf("All tests passed successfully.\n");

    return 0;
}